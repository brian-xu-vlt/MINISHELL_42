#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void sig_handler(int sig)
{
	write(1, "POUETTE\n", 8);
	exit (sig);
}

int main()
{
	signal(SIGINT, sig_handler);
	while(1);
	return (0);
}
