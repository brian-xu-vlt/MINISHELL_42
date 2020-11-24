#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char 	buff[7000];
	int		ret;

	ret = 42;
	sleep (3);
	while (ret > 0)
	{
		bzero(buff, 7000);
		ret = read(0, &buff, 7000);
		printf("[%d][%s]\n", ret, buff);
	}
		printf("last[%d][%s]\n", ret, buff);

	return (0);
}
