#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>

int main(void) {
	MPI_Init(NULL, NULL);//MPI init
	int comm_sz, my_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);//comm size
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);//my rank

	if (my_rank == 0) { //at rank 0
		int i = 0, count = 0, recv, new_arr_size, send_last_size; //init variable
		int dec, dec2, inc2, inc;
		FILE* fp;
		fp = fopen("in.dat", "r");//open in.dat
		fscanf(fp, "%d", &count);//first number = how many 
		int* data = (int*)malloc(sizeof(int) * count);//array for all data
		for (i = 0; i < count; i++) {
			fscanf(fp, "%d", &data[i]);//fill array of data
		}
		int div = count / comm_sz;
		if ((count % comm_sz) != 0) {//if number of process & data tally
			new_arr_size = div + 1;
			send_last_size = count % new_arr_size;// actual data that last process must have
		}
		else {//if number of process & data tally
			new_arr_size = div;
			send_last_size = new_arr_size;
		}
		MPI_Send(&send_last_size, sizeof(send_last_size), MPI_INT, comm_sz - 1, 0, MPI_COMM_WORLD);//send last process how many acutal data need to have
		MPI_Bcast(&new_arr_size, sizeof(new_arr_size), MPI_INT, 0, MPI_COMM_WORLD);//send all process arr size

		int* new_arr = (int*)malloc(sizeof(int) * new_arr_size);//new arr after scatter
		int* cal_arr = (int*)malloc(sizeof(int) * new_arr_size);//calculated array
		int* final_arr = (int*)malloc(sizeof(int) * (new_arr_size * comm_sz));//final array after gather

		if (comm_sz == 1) {//if total process is 1
			for (i = 0; i < count; i++) {
				new_arr[i] = data[i];
			}
			cal_arr[0] = 0;
			cal_arr[1] = 0;
			cal_arr[count - 1] = 0;
			cal_arr[count - 2] = 0;
			for (i = 2; i < count - 2; i++) {
				cal_arr[i] = new_arr[i - 2] + new_arr[i - 1] + new_arr[i + 1] + new_arr[i + 2];
			}
			for (i = 0; i < count; i++) {
				final_arr[i] = cal_arr[i];
			}
			for (i = 0; i < count; i++) {
				printf("[%d] ", final_arr[i]);
			}// calculate at once
		}
		else {//if total process is bigger than 1
			MPI_Scatter(data, new_arr_size, MPI_INT, new_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);//scatter all data

			if (new_arr_size == 1) {//if arr size is 1
				cal_arr[0] = 0;
				int myvalue = new_arr[0];
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank + 2, 2, MPI_COMM_WORLD);//send data to rank2
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 2, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				//recv from rank2 but cal is 0 so no further calculation
			}
			if (new_arr_size >= 2) {//if arr size bigger than 1
				inc2 = new_arr[new_arr_size - 1] + new_arr[new_arr_size - 2];//sum of last & last-1 data
				inc = new_arr[new_arr_size - 1];//last data
				cal_arr[0] = 0; cal_arr[1] = 0;
				MPI_Send(&inc, sizeof(inc), MPI_INT, my_rank + 1, 3, MPI_COMM_WORLD);//send sum to myrank+1
				MPI_Send(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 4, MPI_COMM_WORLD);//send last data to myrank+1
				if (new_arr_size == 2) {//if arr size is 2
					MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);//no further calculation needed
					MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				}
				if (new_arr_size == 3) {//if arr size is 3
					MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

					MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					cal_arr[new_arr_size - 1] = new_arr[new_arr_size - 3] + new_arr[new_arr_size - 2] + inc2;
					//last cal_arr data is (index-2) + (index-1) + (sum of rank+1's first&second data)
				}
				if (new_arr_size >= 4) {//if arr size is 4
					MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					cal_arr[new_arr_size - 2] = new_arr[new_arr_size - 4] + new_arr[new_arr_size - 3] + new_arr[new_arr_size - 1] + inc;
					//last-1 cal_arr data is (index-2) + (index-1) + (index+1) + (rank+1's first data)
					MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					cal_arr[new_arr_size - 1] = new_arr[new_arr_size - 3] + new_arr[new_arr_size - 2] + inc2;
					//last cal_arr data is (index-2) + (index-1) + (sum of rank+1's first&second data)
				}
				for (i = 2; i < new_arr_size - 2; i++) {
					cal_arr[i] = new_arr[i - 2] + new_arr[i - 1] + new_arr[i + 1] + new_arr[i + 2];
					//if calculation can be done at the same rank
				}
			}
			MPI_Gather(cal_arr, new_arr_size, MPI_INT, final_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);//gather all data
			final_arr[count - 1] = 0;
			final_arr[count - 2] = 0;

			for (i = 0; i < count; i++) {
				printf("[%d] ", final_arr[i]);//print final_arr
			}
		}
		printf("\n");
		fclose(fp);
		free(new_arr);//free all data used
		free(data);
		free(cal_arr);
		free(final_arr);
	}
	else if (my_rank < comm_sz-1) {//not last rank & not first rank
		int data, new_arr_size, i;
		int dec, dec2, inc2, inc;
		MPI_Bcast(&new_arr_size, sizeof(new_arr_size), MPI_INT, 0, MPI_COMM_WORLD);//get arr_size from rank0
		int* new_arr = (int*)malloc(sizeof(int) * new_arr_size);
		int* cal_arr = (int*)malloc(sizeof(int) * new_arr_size);

		MPI_Scatter(&data, new_arr_size, MPI_INT, new_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);//get data from rank0
		int arr_sz = new_arr_size;
		for (i = 0; i < new_arr_size; i++) {//init cal_arr
			cal_arr[i] = 0;
		}

		if (new_arr_size == 1) {//if arr size is 1
			int myvalue = new_arr[0];
			if (my_rank == 1) {//at rank 0
				cal_arr[0] = 0;//just send and recv but no calculation need
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank + 1, 1, MPI_COMM_WORLD);
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank + 2, 2, MPI_COMM_WORLD);
				MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 2, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			}
			else if (my_rank == comm_sz -2) {//at before last rank
				cal_arr[0] = 0;//just send and recv but no calculation need
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD);
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank - 2, 4, MPI_COMM_WORLD);
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			}
			else {//other ranks
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank + 1, 1, MPI_COMM_WORLD);//send my data to nearby ranks -1 -2 +1 +2
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank + 2, 2, MPI_COMM_WORLD);
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD);
				MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank - 2, 4, MPI_COMM_WORLD);
				MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = inc;
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 2, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = cal_arr[0] + inc2;
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = cal_arr[0] + dec;
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = cal_arr[0] + dec2;//calculated value is (my_rank-2) + (my_rank-1) + (my_rank +1) + (my_rank+2)
			}
		}
		if (new_arr_size >= 2) {//if arr size bigger than 1
			dec = new_arr[0];//dec is my first data
			dec2 = new_arr[0] + new_arr[1];//dec2 is sum of first&second data
			inc2 = new_arr[new_arr_size - 1] + new_arr[new_arr_size - 2];//inc2 is sum of last&last-1 data
			inc = new_arr[new_arr_size - 1];//inc is my last data
			MPI_Send(&dec, sizeof(dec), MPI_INT, my_rank - 1, 5, MPI_COMM_WORLD);//send dec to rank -1
			MPI_Send(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 6, MPI_COMM_WORLD);//send dec2 to rank -1
			MPI_Send(&inc, sizeof(inc), MPI_INT, my_rank + 1, 3, MPI_COMM_WORLD);//send inc to rank +1
			MPI_Send(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 4, MPI_COMM_WORLD);//send inc2 to rank +1
			if (new_arr_size == 2) {//if arr size is 2
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = inc2 + new_arr[0];
				MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = new_arr[1] + inc;
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = cal_arr[1] + dec;
				//last calculated data is (last data of rank-1) + (first data of new arr) + (sum of first&second of rank +1)
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = cal_arr[0] + dec2;
				//first calculated data is (sum of last two data of rank-1) + (second new arr data) + (first data of rank +1)
			}
			if (new_arr_size == 3) {//if arr size is 3
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[2] = new_arr[1] + new_arr[0] + inc2;
				MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = new_arr[2] + inc;
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = cal_arr[1] + dec + new_arr[0];
				//middle of calculated data is (last of rank-1) + (index-1) + (index+1) + (first of rank+1)
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = dec2 + new_arr[1] + new_arr[2];//same as arr size 2
			}
			if (new_arr_size >= 4) {//if arr size is 4
				MPI_Recv(&inc2, sizeof(inc2), MPI_INT, my_rank + 1, 6, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[new_arr_size - 1] = new_arr[new_arr_size - 3] + new_arr[new_arr_size - 2] + inc2;
				MPI_Recv(&inc, sizeof(inc), MPI_INT, my_rank + 1, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[new_arr_size - 2] = new_arr[new_arr_size - 4] + new_arr[new_arr_size - 3] + new_arr[new_arr_size - 1] + inc;
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = dec + new_arr[0] + new_arr[2] + new_arr[3];
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = dec2 + new_arr[1] + new_arr[2];//similar from above
				for (i = 2; i < new_arr_size - 2; i++) {//if calculation can be done at local
					cal_arr[i] = new_arr[i - 2] + new_arr[i - 1] + new_arr[i + 1] + new_arr[i + 2];
				}
			}
		}

		int final_arr = 0;
		MPI_Gather(cal_arr, new_arr_size, MPI_INT, &final_arr, 0, MPI_INT, 0, MPI_COMM_WORLD);//send final data to rank0

		free(new_arr);//free malloc
		free(cal_arr);
	}
	else{//last rank
		int dec, dec2, inc2, inc;
		int data, new_arr_size, last_size, i;
		MPI_Bcast(&new_arr_size, sizeof(new_arr_size), MPI_INT, 0, MPI_COMM_WORLD);
		int* new_arr = (int*)malloc(sizeof(int) * new_arr_size);
		int* cal_arr = (int*)malloc(sizeof(int) * new_arr_size);

		MPI_Recv(&last_size, sizeof(last_size), MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//actual value for last rank
		MPI_Scatter(&data, new_arr_size, MPI_INT, new_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);
		//get data from rank0
		for (i = last_size; i < new_arr_size; i++) {//empty other data other than last_size
			new_arr[i] = 0;
		}
		int arr_sz = new_arr_size;
		if (new_arr_size == 1) {//if arr size is 1
			cal_arr[0] = 0;
			int myvalue = new_arr[0];
			MPI_Send(&myvalue, sizeof(myvalue), MPI_INT, my_rank - 2, 4, MPI_COMM_WORLD);//send&recv but no calculation needed since it is 0
			MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		}
		if (new_arr_size >= 2) {//if arr size bigger than 2
			dec = new_arr[0];
			dec2 = new_arr[0] + new_arr[1];
			cal_arr[new_arr_size - 1] = 0;
			cal_arr[new_arr_size - 2] = 0;

			MPI_Send(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 6, MPI_COMM_WORLD);//send data to rank-1
			MPI_Send(&dec, sizeof(dec), MPI_INT, my_rank - 1, 5, MPI_COMM_WORLD);
			if (new_arr_size == 2) {//if arrsize is 2
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			}
			if (new_arr_size == 3) {//if arr size is 3
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = dec2 + new_arr[1] + new_arr[2];
				//first data of cal is (sum of last two data of rank-1) + (index+1) + (index +2)
			}
			if (new_arr_size >= 4) {
				MPI_Recv(&dec, sizeof(dec), MPI_INT, my_rank - 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[1] = dec + new_arr[0] + new_arr[2] + new_arr[3];
				//second data is (last data of rank-1) + (index-1) + (index+1) + (index+2)
				MPI_Recv(&dec2, sizeof(dec2), MPI_INT, my_rank - 1, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cal_arr[0] = dec2 + new_arr[1] + new_arr[2];
				//first data is (sum of last two data of rank - 1) + (index + 1) + (index + 2)
				for (i = 2; i < arr_sz -2; i++) {//if calculation can be done by local
					cal_arr[i] = new_arr[i - 2] + new_arr[i - 1] + new_arr[i + 1] + new_arr[i + 2];
				}
			}
		}
		int final_arr = 0;
		MPI_Gather(cal_arr, arr_sz, MPI_INT, &final_arr, 6, MPI_INT, 0, MPI_COMM_WORLD);//send data to rank0

		free(new_arr);//free
		free(cal_arr);
	}
	MPI_Finalize();//finialize
	return 0;
}