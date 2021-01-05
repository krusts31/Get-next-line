#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000 
#endif

int	main(int argc, char **argv)
{
	FILE	*fd;
	int	ret;
	char	*buf;
	int	x;
	int	y;

	fd = fopen(argv[1], "w+");

	x = 0;

	while (x != 10000)
	{
		y = 10000;
		while (y != x)
		{
			fprintf(fd,"%c", 'a');
			y--;
		}
		x++;
		fprintf(fd, "%c", '\n');
	}
	return (0);
}
