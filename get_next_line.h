#ifndef	GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 3000 
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_list
{
	int	*ERROR;
}		t_list;

void		*ft_memset(void *s, int c, size_t n);
size_t  	ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
