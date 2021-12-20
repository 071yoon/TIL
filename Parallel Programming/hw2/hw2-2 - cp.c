#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>

const int STRING_SIZE = 256;

int main(void) {

	FILE* fp;
	fp = fopen("input.txt", "r");//open input.txt
	char buffer[STRING_SIZE], count[8];
	fgets(count, sizeof(count), fp);//얼마나 계산할지 첫 int값 빼오기
	int counter = atoi(count);//정수로 변환

	MPI_Init(NULL, NULL);//MPI시작
	int comm_sz, my_rank, total_sum = 0;//변수 초기화
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);//comm 의 크기 저장
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);//rank의 크기 저장
	int div = counter / comm_sz;
	int arr_size = counter - (comm_sz - 1) * div;//배열의 크기
	char trash[256];//input.txt에서 필요 없는 값 넘어 갈 때 쓸 저장용
	fgets(trash, sizeof(trash), fp);
	int arr[arr_size];//배열 불러오고 초기화
	for (int k = 0; k < arr_size; k++) arr[k] = 0;//init arr[] to 0
	if (my_rank != 0) {//0번 랭크 아닐 때
		if (my_rank < comm_sz - 1) {//마지막 랭크도 아닐 때
			int i = 0, j = 0, sum = 0;
			char* token, * next_token;
			token = strtok_r(trash, " ", &next_token);
			for (i; i < (my_rank * div); i++) {//저장 할 변수가 아닌 만큼 건너띈다
				token = strtok_r(NULL, " ", &next_token);
			} 
			for (i; i < (my_rank + 1) * div; i++){//저장 시작
				arr[j] = atoi(token);//int형으로 배열에 저장
				sum += arr[j++];//저장 한 만큼 바로 sum에 추가한다
				token = strtok_r(NULL, " ", &next_token);
			}
			MPI_Send(&sum, sizeof(sum), MPI_INT, 0, 0, MPI_COMM_WORLD);//send sum to rank 0			
		}
		else {//마지막 랭크 일 때
			int i=0, j=0, sum = 0;
			char* token, * next_token;
			token = strtok_r(trash, " ", &next_token);
			for (i; i < (my_rank * div); i++) {//저장 할 변수가 아니면 스킵
				token = strtok_r(NULL, " ", &next_token);
			}
			for (i; i < counter; i++) {//배열에 저장 시작
				arr[j] = atoi(token);//int형으로 저장
				sum += arr[j++];//sum에 추가
				token = strtok_r(NULL, " ", &next_token);
			}
			MPI_Send(&sum, sizeof(sum), MPI_INT, 0, 0, MPI_COMM_WORLD);//send sum to rank 0	
		}
	}
	else {//0번 랭크
		int i = 0, j = 0, sum = 0, recieve_sum = 0;
		char* token, * next_token;
		token = strtok_r(trash, " ", &next_token);
		for (i; i < div; i++) {//할당량 만큼 바로 저장 시작
			arr[j] = atoi(token);//int형으로 저장
			sum += arr[j++];//sum에 더해준다
			token = strtok_r(NULL, " ", &next_token);
		}
		total_sum = total_sum + sum;
		for (int q = 1; q < comm_sz; q++) {//다른 랭크로부터 sum 값 받아옴
			MPI_Recv(&recieve_sum, sizeof(recieve_sum), MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);//recv sums
			total_sum += recieve_sum;//total sum 계산
		}
		printf("total sum is %d\n", total_sum);//print output
	}
	fclose(fp);
	MPI_Finalize();
	return 0;
}
