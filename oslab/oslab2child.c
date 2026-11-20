#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	pid_t pid = fork();

	if (pid==-1){
		perror("fork");
		return 1;
	}
	if(pid==0){
		printf("child: Work completed.\n");
		return 0;
	}
	if(wait(NULL)==-1){
		perror("Wait");
		return 1;
	}

	printf("Parent: The child has finished.\n");
	return 0;
}   
