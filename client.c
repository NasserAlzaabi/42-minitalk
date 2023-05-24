#include "minitalk.h"

void clientHandler(){ //what to do when signal is recieved with server PID

}

int main(int argc, char** argv){ //argv[1] is PID input argv[2] is string input
	printf("%s", argv[1]);
	int x = atoi(argv[1]);
	if (argc == 3){
		kill(x , SIGUSR1);
	}
	printf("does this even run");
	return 0;
}