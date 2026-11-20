#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int sum = 0;
	pid = fork();

	if(pid==0){
		for (int i=0;i<5;i++){
			sum += i;
		}
		printf("SUM = %d",sum);
		exit(0);
	}
	else if(pid>0){
		WAIT(NULL);
		printf("Parent : Calculation completed \n");
	}

	return 0;
}


