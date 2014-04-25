#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// pid_t childpid;

int main(int argc, char const *argv[])
{
	char* args = {"test", "hej"};
	printf("argc: %d\nargv[0]: %s\n", argc, argv[0]);
	
	execl("/bin/echo", args, NULL);
	/* code */
	return 0;
}