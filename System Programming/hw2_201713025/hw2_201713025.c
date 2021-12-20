#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrimeNumber(int n);
int main(int argc, char *argv[]){
	pid_t childpid = 0;
	int i,n,a,count,status;
	n = atoi(argv[2]); //프로세스 개수 n에 저장
	a = atoi(argv[1]); //범위 a에 저장
	for (i = 1; i < n+1; i++){ //자식 프로세스 n개 생성
		if((childpid = fork())== 0){
		break;
		}
	}
	int k = 0;
	if (childpid == 0){
		for(int j = (i-1)*a/n+1; j<i*a/n+1;j++){ //범위 내에서 소수 계산
			if(isPrimeNumber(j) == 1){
			k +=1 ;
			}
		}
		fprintf(stderr, "Process[%ld] has found %d prime numbers in (%d ~ %d)\n", (long)getpid(), k, (i-1)*a/n+1, i*a/n); //프로세스 ID와 범위에서 몇개 찾았는지 출력 
		return 1; //성공시 1을 리턴
	}
	
	else{
		while(wait(&status) != -1) //자식이 끝날떄 까지 기다린다
			 count += WEXITSTATUS(status); //자식 프로세스의return 값 더해주기
		fprintf(stderr, "%d processes have completed their tasks\n", count);
	}
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
