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
			if ((c[j] & (1 << i))){
				kill(pid, SIGUSR1);
				usleep(350);
				// printf("1");
			}
			else{
				kill(pid, SIGUSR2);
				usleep(350);
				// printf("0");
			}
			// printf("%d", i);
			i--;
		}
		
		// printf("%c: ", c[j]);
		// printf("\n");
		j++;
	}
	
}

int main(int argc, char** argv){ //argv[1] is PID input argv[2] is string input
	int pid;
	
	pid = ft_atoi(argv[1]);
	if (pid < 0){
		write(1, "invalid PID\n", 13);
		exit(0);
	}
	if (argc == 3){
		chartobit(argv[2], pid);
	}
	else
		write(1, "Wrong number of arguments!", 27);

	return 0;
}


