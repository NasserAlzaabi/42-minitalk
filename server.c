#include "minitalk.h"

int getID(){
	int PID;

	PID = getpid();
	return (PID);
}

void serverHandler(){

}

int main(){
	
	printf("The server PID is: %d", getID());
	signal(SIGUSR1, serverHandler);
	signal(SIGUSR2, serverHandler);
	while(1)
		pause();
}