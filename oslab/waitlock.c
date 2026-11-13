#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	for (int i=0;i<3;i++){
		if (fork() == -1){
			perror("fork");
			return 1;
		}
	}

	printf("processs PID: %ld\n",(long)getpid());

	while(wait(NULL)>0){
	}

	return 0;
}


