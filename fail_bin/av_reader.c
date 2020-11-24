#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	printf("ac = %d\n", ac);
	for (int i  = 0; av[i] != NULL; i++)
		printf("av[%d] - [%s]\n", i, av[i]);
	return (0);
}
