/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:35:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/09 22:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int     main(int argc, char **argv)
{
	int             fd;
	int				fd2;
	char            *line;
	char            *line2;
	int             ret;
	int				ret1;
 
	(void)argc;
	line = NULL;
	line2 = NULL;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	ret = 1;
	ret1 = 0;
	while (ret > 0 || ret1 > 0)
	{ 
		if (ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret == 0 || ret == -1)
				return (0);
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
			line = NULL;
		}
		if (ret1 > 0)
		{
			ret1 = get_next_line(fd2, &line2);
			if (ret1 == -1)
				ret = -1;
			printf("%s\n", line2);
			free(line2);
			line2 = NULL;
		}
	}
	return (0);
}
