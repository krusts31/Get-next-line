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

int     main(int argc, char **argv)
{
	int             fd;
//	int				fd2;
	char            *line;
//	char            *line2;
	int             ret;
//	int				ret1;
 
	line = NULL;
	if (argc <= 1)
	{
		printf("PLEASE PASS AN ARGUMENT\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
//	fd2 = open(argv[2], O_RDONLY);
	if (fd > 0)
	{
		ret = 1;
//		ret1 = 1;
		while (ret > 0)
		{ 
			if (ret > 0)
			{
				ret = get_next_line(fd, &line);
			//	if (ret == -1)
			//		ret1 = -1;
				printf("%s\n", line);
				free(line);
				line = NULL;
			}
			/*if (ret1 > 0)
			{
				ret1 = get_next_line(fd2, &line2);
				if (ret1 == -1)
					ret = -1;
				printf("%s", line2);
				free(line2);
				line2 = NULL;
			}
*/
		}
		close(fd);
//		close(fd2);
	}
	/*
	if (fd2 > 0)
	{
		ret = 1;
		while (ret > 0)
		{ 
			printf("%s", line);
			free(line);
		}
		line = NULL;
		close(fd2);
	}
	*/
	return (0);
}
