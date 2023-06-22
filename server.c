#include "minitalk.h"

void serverHandler(int sig)
{
	static char byte;
	static int i;
	
	if (sig == SIGUSR1){
		// printf("1\n"); //prints one extra time after we get correct bit value. gets 1 extra "1" signal from client even though client stores correct bits. results in shift that ruins next char bit values.
		byte++;
		if (i != 7)
			byte = (byte << 1);
		else {
			// printf("\n\nFF %d: %c\n\n", byte, (char)byte);
			ft_putchar_fd(byte, 1);
			byte = 0;
			i = -1;
		}
			
		i++;
	}
	else if (sig == SIGUSR2){
		// printf("0\n");
		if (i != 7)
			byte = byte << 1;
		else{
			// printf("\n\nFF %d: %c\n\n", byte, (char)byte);
			ft_putchar_fd(byte, 1);
			byte = 0;
			i = -1;
		}
		i++;
	}
	// if (i == 8){
		
	// }
	
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