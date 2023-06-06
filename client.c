#include "minitalk.h"

void clientHandler(){ //what to do when signal is recieved with server PID

}

void chartobit(char c){
	for (int i = 7; i >= 0; i--){
		putchar ((c & (1 << i)) ? '1' : '0');
	}
}

int main(int argc, char** argv){ //argv[1] is PID input argv[2] is string input
	chartobit(argv[1][0]);
	// if (argc == 3){
	// 	//kill(x , SIGUSR1);
	// }
	// printf("does this even run");
	return 0;
}