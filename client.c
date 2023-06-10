#include "minitalk.h"

void clientHandler(){ //what to do when signal is recieved with server PID

}

void chartobit(char *c, int pid){
	int j;
	int i;

	
	j = 0;
	while(c[j] != '\0'){
		i = 7;
		while (i >= 0){
			if ((c[j] & (1 << i))){ //sends extra sig1 signal after all bit info has been sent.
				kill(pid, SIGUSR1);
				usleep(300);
				printf("1");
			}
			else{
				kill(pid, SIGUSR2);
				usleep(300);
				printf("0");
			}
			// printf("%d", i);
			i--;
		}
		
		
		printf("%c: ", c[j]);
		// while (n < 8){
		// 	printf("%d", m[n++]);
		// }
		printf("\n");
		j++;
	}
	
}

int main(int argc, char** argv){ //argv[1] is PID input argv[2] is string input
	
	chartobit(argv[2], atoi(argv[1]));
	if (argc == 3){
		kill(atoi(argv[1]), SIGUSR1);
	}
	
	return 0;
}


