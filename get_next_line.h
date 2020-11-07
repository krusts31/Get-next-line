/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:41:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/07 15:15:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 150 
# include <fcntl.h>
# include <stdio.h> //remove this library when ubmitting
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	int				ptr;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	char			*hold;
	struct s_list	*next;
}			t_list;

void    *ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memove(char *dst, char *src);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int	get_next_line(int fd, char **line);
size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s);
#endif
