#include <stdio.h>
#include <unistd.h>

int main(){
	int i;
	pid_t pid;
	for(i = 0; i < 4; i++){
		fork();
		pid = getpid();
		printf("pid = %d\n", pid);
	}
	return (0);
}

