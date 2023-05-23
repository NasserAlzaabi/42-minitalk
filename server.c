#include "minitalk.h"

int getID(){
	int PID;

	PID = getpid();
	return (PID);
}

int main(){
	printf("%d", getID());
}