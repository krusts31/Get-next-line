/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:38:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/09 22:18:22 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_new_list(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->ptr = 0;
	new->ret = 1;
	ft_memset(new->buf, 0, BUFF_SIZE + 1);
	new->join = NULL;
	new->hold = NULL;
	new->next = NULL;
	return (new);
}

static int	ft_free_list(t_list *list, int ret)
{
	t_list	*tmp;
	t_list	*next_tmp;

	if (list->ret <= 0)
	{
		tmp = list->next;
		free (list);
		list = tmp;
		return (ret);
	}
	if (list->next == NULL)
	{
		free (list);
		return (ret);
	}
	while (list->ret > 0)
	{
		tmp = list;
		list = list->next;
	}
	next_tmp = list->next;
	free (list);
	list = tmp;
	list->next = next_tmp;
	return (ret);
}

static char	*ft_get_line(t_list *list)
{
	char	*tmp;
	char	*ret;

	ret = ft_strdup(list->buf, list);
	list->ptr++;
	ft_memset(list->buf, 0, list->ptr);
	if (list->hold != NULL)
	{
		tmp = ft_strjoin(list->hold, ret);
		free (list->hold);
		list->hold = NULL;
		free (ret);
	}
	else
		tmp = ret;
	return (tmp);
}

/*
**	
*/

static int	ft_read_file(t_list *list, char **line)
{
	while (list->buf[list->ptr] != '\n' && list->ret != 0)
	{
		if (list->buf[list->ptr] == '\0')
		{
			if (list->hold == NULL)
				list->hold = ft_strdup(list->buf, list);
			else
			{
				list->join = ft_strjoin(list->hold, list->buf);
				free (list->hold);
				list->hold = list->join;
			}
			list->ret = read(list->fd, list->buf, BUFF_SIZE);
			list->ptr = 0;
			if (list->ret < 0)
				return (-1);
		}
		list->ptr++;
	}
	*line = ft_get_line(list);
	return ((list->ret) ? 1 : 0);
}

int	get_next_line(int fd, char **line)
{
	static	t_list	*list = NULL;
	t_list			*ptr;
	int				ret;

	if (line == NULL || BUFF_SIZE <= 0 || fd <= 0)
		return (ft_lstclear(list, -1));
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
			return (ft_lstclear(list, -1));
	}
	ret = ft_read_file(ptr, line);
	if (ret <= 0)
		return (ft_free_list(list, ret));
	return (ret);
}
