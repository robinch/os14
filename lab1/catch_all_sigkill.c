/* 	
	catch_all_sigkills.c
	
	This program will create a child process that catches all sigkill and does nothing.
	This code is inspired by signaltest.c in the course material "Användbara systemanrop
	och bibliotekfunctioner
*/

#include <sys/types.h> /* Defines the type pid_t */
#include <stdio.h> /* Defines stderr where I will write my error messages */
#include <stdlib.h> /* Standard lib */
#include <unistd.h> /* Defines sleep and other */
#include <signal.h> /* Defines signal names and other */

#define TRUE ( 1 ) /* Defines TRUE as one so I can use it as a bool */

pid_t childpid; /* pid for the child from fork */

	/* Is called when a SIGKILL */
	void kill_handler(int signal_code) {
		if(signal_code == SIGKILL){
			/* What happens when the signal is a SIGKILL */
			printf("Recieved SIGKILL\n");
		}

	}
	int main(int argc, char const *argv[])
	{
		childpid = fork(); /* Creates the child process */

		if (0 == childpid) {
			/* code that the child will execute */				

			if (signal(SIGKILL, kill_handler) == SIG_ERR){ /* Makes so when a SIGKILL happen 
																the kill_handler function is
																called 
															*/
        		fprintf(stderr, "can't catch SIGKILL\n"); /* If it can't handle 
        														the SIGKILL 
        													*/
        	}

        	while(TRUE){} /* So that the child process keeps going forever or until it's killed */
			
		}else if( -1 == childpid){
			fprintf(stderr, "Fork failed");
			/* If fork fails */
		}else {
			/* Code for parent */
			sleep(5); /* number of seconds the program is ran */
			kill(childpid, SIGKILL); /* Kills the child so no zombie procsesses occurs */
		}
		return 0;
	}