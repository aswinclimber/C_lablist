#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0){
		printf("child proccess\n");
		exit(7);
	}
	else if (pid > 0){
		wait(&status);
		if (WIFEXITED(status)){
			printf("Child exit code : %d\n",WEXITSTATUS(status));
		}
	}
	return 0;
}

