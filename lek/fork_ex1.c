#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int pid;

	pid = fork();
	if (0 == pid) {
		printf("Child pid : %d\n", getpid());
	}else if( pid == -1){
		printf("Error!\n");
	}else {
		printf("Parent pid : %d\n", getpid());
	}
	return 0;
}