#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 9 
# include <fcntl.h>
# include <stdio.h>
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

void	ft_strclr1(char *s, int flag);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memove(char *dst, char *src);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int	get_next_line(int fd, char **line);
t_arr	*ft_newlist(const int fd);

#endif
