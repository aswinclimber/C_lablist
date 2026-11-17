#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;

	for(int i=1;i<=2;i++){
		pid = fork();

		if (pid==0){
			printf("Child %d : PID = %d\n",i,getpid());
			exit(0);
		}
		else if (pid == -1){
			perror("fork");
			return 1;
		}

	}

	for (int i = 1; i<=2;i++){
		wait(NULL);
	}
	printf("Parent : Both children have finished.\n");
	return 0;
}


			
