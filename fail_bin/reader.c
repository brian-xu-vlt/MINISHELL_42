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
	char 	buff[2];
	int		ret;

	ret = 42;

	while (ret > 0)
	{
		ret = read(0, &buff, 1);
		buff[1] = '\0';
		printf("[%d][%s]", ret, buff);
		buff[0] = '\0';
	}
		printf("last[%d][%s]\n", ret, buff);

	return (0);
}
