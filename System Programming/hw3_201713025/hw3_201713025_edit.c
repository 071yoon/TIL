#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define BLKSIZE 1000
int isPrimeNumber(int n);
int main(int argc, char *argv[]){
	int fd[2];
	int i,n,a,status;
	char buf[BLKSIZE] = { 0, }; //buf 0으로 초기화
	int res = 0;
	n = atoi(argv[2]); //프로세스 개수 n에 저장
	a = atoi(argv[1]); //범위 a에 저장
	pthread_t* tid;
	tid = (pthread_t*)calloc(n, sizeof(pthread_t));
	for (i = 0; i < n; i++){ //자식 프로세스 n개 생성
		int arr[0] = i * a / n + 1;
		int arr[1] = (i + 1) * a / n + 1;
		if(error = pthread_create(tid+i, NULL, isPrimecount, (void*)&arr)){
			fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
			tid[i] = pthread_self();
		break;
		}
	}
	int k = 0;
	/*
	if (childpid == 0){
		for(int j = (i-1)*a/n+1; j<i*a/n+1;j++){ //범위 내에서 소수 계산
			if(isPrimeNumber(j) == 1){
			k +=1 ;
			}
		}
		fprintf(stderr, "[%ld] has found %d prime numbers in (%d ~ %d)\n",
			(long)getpid(), k, (i-1)*a/n+1, i*a/n);
		//프로세스 ID와 범위에서 몇개 찾았는지 출력 
		sprintf(buf, "%d", k);//소수값 string으로 변환
		write(fd[1], buf, BLKSIZE);//buf로 전송
		return 1; //성공시 1을 리턴
	}*/
	/*
	else{
		while (wait(&status) != -1) { //자식이 끝날떄 까지 기다린다
			read(fd[0], buf, BLKSIZE); //buf로 수신
			res += atoi(buf);//buf정수로 변환 후 res에 저장
		}
		fprintf(stderr, "[%ld] has found %d prime numbers in (%d ~ %d)\n",
			(long)getpid(), res, 1, a);
	}*/
	return 0;
}

int isPrimeNumber(int n){
	int i = 0;
	int last = n/2;
	if (n <= 1)
		return 0;
	for (i = 2; i <= last; i++){
		if ((n%i) == 0)
			return 0;
	}
	return 1;
}
int isPrimecount(int arr) {
	int k = 0;
	for (int i = arr[0]; i < arr[1]; i++) {
		if (isPrimeNumber(j) == 1) {
			k += 1;
		}
	}
	return k;
	fprintf(stderr, " has found %d prime numbers in (%d ~ %d)\n",
		 k, arr[0], arr[1]);
}

