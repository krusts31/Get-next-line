/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 12:26:50 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/09 22:20:21 by alkrusts      ########   odam.nl         */
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

	if (s == NULL)
		return (0);
	retu = 0;
	while (s[retu] != '\0')
		retu++;
	return (retu);
}

int		ft_lstclear(t_list *list, int ret)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free (list);
		list = tmp;
	}
	return (ret);
}

char	*ft_strdup(const char *s, t_list *list)
{
	char	*ptr;
	size_t	x;
	size_t	y;
	int	hold;

	y = 0;
	x = 0;
	if (*s == '\0' && list->buf[list->ptr] == '\n')
	{
		hold = list->ptr;
		while (list->buf[hold] != '\0')
		{
			hold--;
			x++;
		}
		hold = list->ptr;
		ptr = malloc((x + 1) * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, 0, x + 1);
		while (list->buf[hold] != '\0')
		{
			ptr[x] = list->buf[hold];
			x--;
			hold--;
		}
		return (ptr);
	}	
	x = ft_strlen(s);
	ptr = malloc((x + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, x + 1);
	while (s[y])
	{
		if (s[y] == '\n')
			break ;
		ptr[y] = s[y];
		y++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr1;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr1 = malloc((len + 1) * sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	ft_memset(ptr1, 0, len + 1);
	ret = ptr1;
	while (*s1)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	while (*s2)
	{
		*ret = *s2;
		ret++;
		s2++;
	}
	return (ptr1);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	x;

	size = 0;
	if (s == NULL)
		return (NULL);
	x = ft_strlen((char *)s);
	ptr = malloc((len + 1) * sizeof(char));
	memset(ptr, 0, len + 1);
	if (ptr == NULL)
		return (NULL);
	while (size != len)
	{
		ptr[size] = s[start]
		size++;
		start++;
	}
	return (ptr);
}
*/
