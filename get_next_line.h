/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:41:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/14 16:41:45 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	size_t				ptr;
	int				ret;
	size_t				position;
	char				*tmp;
	char				*rest;
	int				pos;
	struct s_list	*next;
}			t_list;

void	ft_con(t_list *i, char *b);
char    *ft_strjoin(char const *s1, char const *s2);
void	*ft_memove(char *dst, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_list *list);
int	get_next_line(int fd, char **line);
char    *ft_strchr(const char *str, int c);
size_t  ft_strlen(const char *s);

#endif
