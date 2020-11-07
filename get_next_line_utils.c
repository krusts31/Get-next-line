#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
