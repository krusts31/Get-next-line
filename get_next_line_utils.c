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

int	len_to_char(char *line, char hit, int ret, t_list123 *info)
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
	free(info->rem);
	free(info->tmp);
	free(info);
	return (ret);
}

int	ft_con(t_list123 *info, char **line)
{
	while (info->buf[info->y] != '\n' && info->buf[info->y] != '\0')
	{
		info->tmp[info->x] = info->buf[info->y];
		info->x++;
		info->y++;
	}
	if (info->buf[info->y] == '\n')
	{
		info->len = len_to_char(info->buf + info->y + 1, '\0', 0, info);
		info->rem = malloc(sizeof(char) * info->len + 1);
		if (info->rem == NULL)
			return (len_to_char(NULL, 'x', -1, info));
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

int	inti_list(t_list123 **info, int fd)
{
	*info = malloc(sizeof(t_list123) * 1);
	if (*info == NULL)
		return (-1);
	(*info)->index = 0;
	(*info)->rem = NULL;
	(*info)->prev = 0;
	(*info)->next = NULL;
	(*info)->tmp = NULL;
	(*info)->ret = 1;
	(*info)->fd = fd;
	return (1);
}
