/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:41:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/01/05 21:55:56 by alkrusts      ########   odam.nl         */
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

typedef struct	s_list
{
	struct s_list	*next;
	char			*rem;
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];
	size_t			index;
	size_t			prev;
	size_t			x;
	size_t			y;
	size_t			len;
	int				ret;
	int				fd;
}				t_list123;

int				get_next_line(int fd, char **line);
int				len_to_char(char *line, char hit, int ret, t_list123 *info);
int				ft_con(t_list123 *info, char **line);
int				inti_list(t_list123 **info, int fd);
#endif
