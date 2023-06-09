#include "minitalk.h"

void serverHandler(int sig)
{
	static int byte;
	static int i;

	//i = 0;
	//byte = 0;
	if (i == 8){
		byte = 0;
		i = 0;
	}
	if (sig == SIGUSR1){
		byte++;
		byte = (byte >> 1);
		i++;
		//printf("recieved 1\n");
	}
	else if (sig == SIGUSR2){
		byte = byte >> 1;
		i++;
		//printf("recieved 0\n");
	}
	printf("%d\n", byte);
}

char bittochar(){
	char result;

	result = 'A';
	return (result);
}

int main(){
	int PID;

	PID = getpid();
	printf("The server PID is: %d\n", PID);
	//fflush(stdout);
	while(1){
		signal(SIGUSR1, serverHandler);
		signal(SIGUSR2, serverHandler);
		pause();
	}
	return 0;
}