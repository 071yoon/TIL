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
		MPI_Scatter(data, new_arr_size, MPI_INT, new_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);//scatter all data

		for (i = 0; i < new_arr_size; i++) {
			printf("[%d] [%d] ", my_rank, new_arr[i]);
		}
		fclose(fp);
		free(new_arr);//free all data used
		free(data);
		free(cal_arr);
		free(final_arr);
		printf("\n");
	}
	else if (my_rank < comm_sz - 1) {//not last rank & not first rank
		int data, new_arr_size, i, recv_data;
		int dec, dec2, inc2, inc;
		MPI_Bcast(&new_arr_size, sizeof(new_arr_size), MPI_INT, 0, MPI_COMM_WORLD);//get arr_size from rank0
		int* new_arr = (int*)malloc(sizeof(int) * new_arr_size);
		int* cal_arr = (int*)malloc(sizeof(int) * new_arr_size);

		MPI_Scatter(&data, new_arr_size, MPI_INT, new_arr, new_arr_size, MPI_INT, 0, MPI_COMM_WORLD);//get data from rank0
		printf("%d is recvdata\n", new_arr_size);
		if (recv_data == 0) {
			for (i = 0; i < new_arr_size; i++) {
				new_arr[i] = 0;
			}
		}
		int arr_sz = new_arr_size;

		for (i = 0; i < new_arr_size; i++) {
			printf("[%d] [%d] ", my_rank, new_arr[i]);
		}

		for (i = 0; i < new_arr_size; i++) {//init cal_arr
			cal_arr[i] = 0;
		}


		int final_arr = 0;

		free(new_arr);//free malloc
		free(cal_arr);
		printf("\n");

	}
	else {//last rank
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

		for (i = 0; i < new_arr_size; i++) {
			printf("[%d] [%d] ", my_rank, new_arr[i]);
		}


		int arr_sz = new_arr_size;
		
		int final_arr = 0;

		free(new_arr);//free
		free(cal_arr);
		printf("\n");

	}
	MPI_Finalize();//finialize
	return 0;
}