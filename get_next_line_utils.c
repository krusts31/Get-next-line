/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:57:11 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/01/05 21:51:07 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		len_to_char(char *line, char hit, int ret, t_list123 **info)
{
	int	x;

	if (hit != 'x')
	{
		x = 0;
		if (line == NULL)
			return (0);
		while (line[x] != hit && line[x] != '\0')
			x++;
		return (x);
	}
	while (*info)
	{
		free((*info)->rem);
		(*info)->rem = NULL;
		(*info) = (*info)->next;
	}
	free(*info);
	return (ret);
}

int		ft_con(t_list123 *info, char **line)
{
	while (info->buf[info->y] != '\n' && info->buf[info->y] != '\0')
	{
		info->tmp[info->x] = info->buf[info->y];
		info->x++;
		info->y++;
	}
	if (info->buf[info->y] == '\n')
	{
		info->len = len_to_char(info->buf + info->y + 1, '\0', 0, &info);
		info->rem = malloc(sizeof(char) * info->len + 1);
		if (info->rem == NULL)
			return (len_to_char(NULL, 'x', -1, &info));
		info->rem[info->len] = '\0';
		info->x = 0;
		info->y++;
		while (info->buf[info->y] != '\0')
		{
			info->rem[info->x] = info->buf[info->y];
			info->y++;
			info->x++;
		}
		info->rem[info->x] = '\0';
	}
	*line = info->tmp;
	return (1);
}

t_list123	*init_list(int fd)
{
	t_list123	*info;

	info = malloc(sizeof(t_list123) * 1);
	if (info == NULL)
		return (NULL);
	info->next = NULL;
	info->rem = NULL;
	info->tmp = NULL;
	info->index = 0;
	info->prev = 0;
	info->ret = 1;
	info->fd = fd;
	return (info);
}


t_list123	*ft_lstadd_back(t_list123 **lst, t_list123 *new)
{
	if (new == NULL)
		return (NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
	}
	return ((*lst)->next);
}

int		deleteNode(t_list123 **info)
{
	t_list123 *tmp;
	t_list123 *prev;

	tmp = *info;
	if (tmp != NULL && tmp->ret == 0)
	{
		*info = (*info)->next;
		free(tmp->rem);
		free(tmp);
		return (0);
	}
	while (tmp != NULL && tmp->ret != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	prev->next = tmp->next;
	free(tmp->rem);
	free(tmp);
	return (0);
}
