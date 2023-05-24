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
	
}