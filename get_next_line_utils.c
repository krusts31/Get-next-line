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

void	ft_con(t_list *i, char *b)
{
	if (i->rest == NULL)
		i->rest = ft_substr(b, i->ptr, ft_strlen(b), NULL);
	else
	{
		i->tmp = ft_strjoin(i->rest, b);
		free (i->rest);
		i->rest = i->tmp;
	}
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	x;
	size_t	y;

	y = 0;
	x = ft_strlen(s);
	ptr = malloc(x * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[x] = '\0';
	while (s[y])
	{
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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr1 = malloc((len + 1) * sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	ptr1[len] = '\0';
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

char	*ft_substr(char const *s, unsigned int start, size_t len, t_list *list)
{
	char	*ptr;
	size_t	size;

	size = 0;
	if (s == NULL)
		return (NULL);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (size != len && s[start] != '\0')
	{
		if (list != NULL)
			list->ptr++;
		if (s[start] == '\n')
			break ;
		ptr[size] = s[start];
		size++;
		start++;
	}
	ptr[size] = '\0';
	return (ptr);
}
