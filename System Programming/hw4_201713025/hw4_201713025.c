#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>
int isPrimeNumber(int n);
void* testthread(void* arr);
sem_t semA;

int main(int argc, char* argv[]) {
	sem_init(&semA, 0, 1);
	int i, n, a, total = 0;
	void *tret = NULL;
	n = atoi(argv[2]); //쓰레드의 개수 n에 저장
	a = atoi(argv[1]); //범위 a에 저장
	pthread_t* tid;
	tid = (pthread_t*)calloc(n, sizeof(pthread_t));//쓰레드의 개수만큼 tid malloc
	int arr[n][2];
	for (i = 0; i < n; i++) { //thread n개 생성
		arr[i][0] = i * a / n + 1;//쓰레드 시작 수
		arr[i][1] = (i + 1) * a / n;//쓰레드의 끝 수
	}
	sem_wait(&semA);//i 를 제공 하기 전 한명만 진입하게 block
	for (i = 0; i < n; i++) {
		tid[i] = pthread_self();
		pthread_create(&tid[i], NULL, testthread, (void*)&arr[i]);//thread 생성
	}
	
	for (i = 0; i < n; i++) {
		pthread_join(tid[i], &tret);//리턴받은 k를 주소값에 저장
		total += *((int*)tret);//int형으로 변환 후 total 에 더해준다
	}

	printf("The main thread[%ld] has found %d prime numbers in (%d ~ %d).\n", 
		pthread_self(),total,1,a);
	free(tid);//malloc 해제
	return 0;
}
int isPrimeNumber(int n) {
	int i = 0;
	int last = n / 2;
	if (n <= 1)
		return 0;
	for (i = 2; i <= last; i++) {
		if ((n % i) == 0)
			return 0;
	}
	return 1;
}
void* testthread(void* arr) {
	sem_post(&semA);//i를 할당 받고 다시 unblock 해준다
	int arrint[2];
	int *k = (int*)malloc(sizeof(int)*1);
	//메인 쓰레드에서 받을 때 힙 공간에 저장 해야 전달이 되므로 malloc 사용
	arrint[0] = ((int*)arr)[0];
	arrint[1] = ((int*)arr)[1];
	for (int i = arrint[0]; i < arrint[1]+1; i++) {
		if (isPrimeNumber(i) == 1) {
			k[0] += 1;
		}
	}
	fprintf(stderr, "Thread[%ld] has found %d prime numbers in (%d ~ %d).\n",
		pthread_self(), k[0], arrint[0], arrint[1]);
	pthread_exit(k);//포인터로 전달
	free(k);
}