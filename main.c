#include "get_next_line.h"

int     main(int argc, char **argv)
{
	int             fd;
	int             i;
	char            *line;
	int             ret;
 
	ret = 1;
	line = NULL;
	i = 1;
	while (argc > 0)
	{
		fd = open(argv[i], O_RDONLY);
			while (ret > 0)
			{ 
				ret = get_next_line(fd, &line);
				printf("%s\n", line);
				if (line != NULL)
					free(line);
			}
		close(fd);
		argc--;
		i++;
	}
	return (0);
}
