/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 12:26:50 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/07 15:39:04 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

size_t	ft_strlen(const char *s)
{
	size_t	retu;

	retu = 0;
	while (*s != '\0')
	{
		retu++;
		s++;
	}
	return (retu);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	x;
	size_t	y;

	y = 0;
	x = ft_strlen(s);
	ptr = malloc((x + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, x + 1);
	while (s[y] != '\0')
	{
		ptr[y] = s[y];
		y++;
	}
	return (ptr);
}
