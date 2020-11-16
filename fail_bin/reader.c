#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char 	buff[2];
	int		ret;

	ret = 42;
	while (ret > 0)
	{
		ret = read(0, &buff, 1);
		buff[1] = '\0';
		printf("[%d][%s]\n", ret, buff);
		buff[0] = '\0';
	}
		printf("last[%d][%s]\n", ret, buff);

	return (0);
}
