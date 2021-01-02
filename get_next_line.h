/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:41:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/09 22:10:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char		*rem;
	char		*tmp;
	size_t		index;
	size_t		prev;
	size_t		x;
	size_t		y;
	size_t		len;
	int		ret;
}			t_list123;

int     get_next_line(int fd, char **line);

#endif
