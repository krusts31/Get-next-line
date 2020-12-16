/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:38:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/14 16:36:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static t_list	*ft_new_list(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->ptr = 0;
	new->next = NULL;
	new->position = 0;
	new->ret = 1;
	new->rest = NULL;
	new->pos = 0;
	new->tmp = NULL;
	return (new);
}

static int	ft_free_list(t_list *list, int r)
{
	t_list	*tmp;
	t_list	*next_tmp;

	while (list->next != NULL)
	{
		tmp = list;
		list = list->next;
		if (list == NULL)
		{
			free(tmp);
			tmp = NULL;
			return (list->ret);
		}
		if (list->ret <= 0)
		{
			next_tmp = list->next;
			free(list);
			tmp->next = next_tmp;
			return (r);
		}
	}
	return (r);
}

static int	ft_read_c(t_list *i, char **l, char *b)
{
	if (b[i->position] == '\n')
	{
		if (i->rest == NULL)
			*l = ft_substr(b, i->ptr, ft_strlen(b), i);
		else
		{
			*l = ft_strjoin(i->rest, ft_substr(b, 0, ft_strlen(b), i));
			free (i->rest);
			i->rest = NULL;
		}
		i->position++;
		return (1);
	}
	if (b[i->position] == '\0')
	{
		ft_con(i, b);
		i->ptr = 0;
		i->position = 0;
		i->pos = 1;
	}
	return (0);
}

static int	ft_read_file(t_list *list, char **line)
{
	char	buf[BUFFER_SIZE + 1];

	while (list->ret > 0)
	{
		if (list->position == 0 || list->pos == 1)
		{
			list->ret = read(list->fd, buf, BUFFER_SIZE);
			if (list->ret == 0 || list->ret == -1)
				return (list->ret == 0 ? 0 : -1);
			buf[list->ret] = '\0';
			list->pos = 0;
			list->ptr = 0;
		}
		if (ft_read_c(list, line, buf))
		{
			if (*line == NULL)
				return (-1);
			return (1);
		}
		if (list->pos != 1)
			list->position++;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static	t_list	*list = NULL;
	t_list			*ptr;
	int				ret;

	if (line == NULL ||  BUFFER_SIZE <= 0 || fd <= 0)
		return (-1);
	if (!list)
		list = ft_new_list(fd);
	if (list == NULL)
		return (-1);
	ptr = list;
	while (fd != ptr->fd)
	{
		if (ptr->next == NULL)
			ptr->next = ft_new_list(fd);
		ptr = ptr->next;
		if (ptr == NULL)
			return (ft_free_list(list, -1));
	}
	ret = ft_read_file(ptr, line);
	if (ret <= 0)
		return (ft_free_list(list, ret));
	return (ret);
}
