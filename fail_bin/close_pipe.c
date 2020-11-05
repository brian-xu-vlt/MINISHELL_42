#include <unistd.h>

int main()
{
	close(0);
	close(1);
	return (0);
}
