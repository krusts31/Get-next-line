#include "get_next_line.h"

int     main(int argc, char **argv)
{
	int             fd;
	int				fd2;
	char            *line;
	int             ret;
 
	line = NULL;
	if (argc <= 1)
	{
		printf("PLEASE PASS AN ARGUMENT\n");
		return (-1);
	}
	while (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		ret = 1;
		while (ret > 0)
		{ 
			ret = get_next_line(fd, &line);
			printf("%s", line);
			free(line);
		}
		ret = 1;
		close(fd);
		while (ret > 0)
		{ 
			ret = get_next_line(fd2, &line);
			printf("%s", line);
			free(line);
		}
		close(fd2);
		argc--;
	}
	return (0);
}
