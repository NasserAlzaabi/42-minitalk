#include "minitalk.h"

void serverHandler(int sig)
{
	static int byte;
	static int i;
	
	
	if (sig == SIGUSR1){
		printf("1\n"); //prints one extra time after we get correct bit value. gets 1 extra "1" signal from client even though client stores correct bits. results in shift that ruins next char bit values.
		byte++;
		if (i != 7)
			byte = (byte << 1);
		else 
			printf("\nFF %d\n", byte); //tests if end value correct
		i++;
	}
	else if (sig == SIGUSR2){
		printf("0\n");
		if (i != 7)
			byte = byte << 1;
		i++;
	}
	else
		printf("none\n");
	if (i >= 8){
		printf("Final: %d\n", byte);
		byte = 0;
		i = 0;
	}
	
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
	while(1){
		signal(SIGUSR1, serverHandler);
		signal(SIGUSR2, serverHandler);
		pause();
	}
	return 0;
}