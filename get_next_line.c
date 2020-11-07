/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:38:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/07 16:58:48 by alkrusts      ########   odam.nl         */
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
	ft_memset(new->buf, 0, BUFF_SIZE + 1);
	new->str = NULL;
	new->hold = NULL;
	new->next = NULL;
	return (new);
}

static int	ft_free_list(t_list *list, int ret)
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

static char	*ft_read_file(t_list *list)
{
	if (list->buf[list->ptr] == '\0')
	{
		list->ret = read(list->fd, list->buf, BUFF_SIZE);
		list->ptr = 0;
		if (list->ret < 0)
			return (NULL);
	}
	return (ft_strdup(list->buf));
}

static int	ft_get_line(t_list *list, char **line)
{
	*line = ft_read_file(list);
	ft_memset(list->buf, 0, BUFF_SIZE + 1);
	return (ft_strlen(*line));
} 

int	get_next_line(int fd, char **line)
{
	static	t_list	*list;
	t_list			*ptr;
	int				ret;

	if (fd < 0)
		return (ft_free_list(list, -1));
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
	ret = ft_get_line(ptr, line);
//	if (ret == 0)
//		return (ft_free_list(list, 0));
	return (ret);
}
