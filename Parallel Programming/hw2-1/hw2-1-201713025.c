#include<stdio.h>
#include<mpi.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    clock_t start, end;//시간변수 시 사용
    double num = 100000000;
    int rank, size, n;
    double* send_msg; double* recv_msg;
    send_msg = malloc(num*sizeof(double));//num의 크기로 send_msg배열 동적할당
    recv_msg = malloc(num*sizeof(double));//num의 크기로 recv_msg배열 동적할당
    MPI_Init(&argc, &argv);//MPI 시작
    MPI_Status status;//MPI status
    MPI_Request request;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);//MPI의 rank지정
    MPI_Comm_size(MPI_COMM_WORLD, &size);//MPI의 size = process의 개수
    
    if (rank == 0) n = 1;
    else n = 0;
    
    for (int i =0; i < num; i ++){
        send_msg[i] = i *(rank + 1);
    }
    int counter = 1; int max_counter = 10;
    start = clock();//rank0이 보내기 직전에 clock을 시작한다
    for(counter = 0; counter < max_counter; counter++){
        if (rank == 0){
            MPI_Send(send_msg, num, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);//pingpong 시작
            //printf("rank = %d, sent = %d\n", rank, counter);
            MPI_Recv(recv_msg, num, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &status);
            //printf("rank = %d, recv = %d\n", rank, counter);
        }
        if (rank == 1){
            MPI_Recv(recv_msg, num, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
            //printf("rank = %d, recv = %d\n", rank, counter);
            MPI_Send(send_msg, num, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
            //printf("rank = %d, sent = %d\n", rank, counter);
        }
    }
    end = clock();//마지막 counter가 끝난 후 즉 loop을 빠져나오는 순간 끝나는 시간을 저장한다
    float res = (float)(end - start);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0){ //소요된 시간 한번만 출력하도록 rank 0 에서만 출력
        printf("배열의 크기 : %.f\ncounter의크기 : %d\n소요된 시간 : %.f microseconds\n",num, max_counter,res);
    }
    free(send_msg);
    free(recv_msg);
    MPI_Finalize();
}
