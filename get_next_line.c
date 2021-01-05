/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:56:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/01/05 21:50:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_line(char **line, t_list123 *info)
{
	if (info->ret < 0)
		return (-1);
	info->len = len_to_char(info->rem, '\0', 0, info) + info->index;
	info->prev = 1;
	info->x = 0;
	info->y = 0;
	info->tmp = malloc((info->len * sizeof(char)) + 1);
	if (info->tmp == NULL)
		return (len_to_char(NULL, 'x', -1, info));
	info->tmp[info->len] = '\0';
	if (info->rem != NULL)
	{
		while (info->rem[info->x] != '\0')
		{
			info->tmp[info->x] = info->rem[info->x];
			info->x++;
		}
		free(info->rem);
		info->rem = NULL;
	}
	info->index++;
	return (ft_con(info, line));
}

static int	ft_null_byte(t_list123 *info)
{
	info->y = info->index + len_to_char(info->rem, '\0', 0, info);
	info->tmp = malloc(sizeof(char) * info->y + 1);
	if (info->tmp == NULL)
		return (len_to_char(NULL, 'x', -1, info));
	info->tmp[info->y] = '\0';
	while (info->y != 0 && info->x != 0)
	{
		info->y--;
		info->x--;
		info->tmp[info->y] = info->buf[info->x];
	}
	if (info->rem != NULL)
	{
		info->x = len_to_char(info->rem, '\0', 0, info);
		while (info->y != 0 && info->x != 0)
		{
			info->y--;
			info->x--;
			info->tmp[info->y] = info->rem[info->x];
		}
		free(info->rem);
	}
	info->rem = info->tmp;
	info->prev = 0;
	return (1);
}

static void	read_and_copy(t_list123 *info)
{
	info->x = 0;
	if (info->prev == 0)
	{
		info->ret = read(info->fd, info->buf, BUFFER_SIZE);
		if (info->ret < 0)
		{
			len_to_char(NULL, 'x', -1, info);
			info->buf[0] = '\0';
		}
		info->buf[info->ret] = '\0';
		info->index = 0;
	}
	else
	{
		while (info->rem[info->x] != '\0')
		{
			info->buf[info->x] = info->rem[info->x];
			info->x++;
		}
		info->buf[info->x] = '\0';
		free(info->rem);
		info->rem = NULL;
		info->index = 0;
		info->prev = 1;
	}
}

int			get_next_line(int fd, char **line)
{
	static t_list123	*info = NULL;

	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!info)
		inti_list(&info, fd);
	if (info == NULL)
		return (-1);
	while (info->ret)
	{
		read_and_copy(info);
		while (info->buf[info->index])
		{
			if (info->buf[info->index] == '\n')
				return (ft_new_line(line, info));
			info->index++;
		}
		info->x = len_to_char(info->buf, '\0', 0, info);
		if (!ft_null_byte(info))
			return (-1);
	}
	return (len_to_char(NULL, 'x', 0, info));
}
