#include "get_next_line.h"

size_t		len_to_char(char *line, char hit)
{
	size_t	x;

	x = 0;
	if (line == NULL)
		return (0);
	while (line[x] != hit && line[x] != '\0')
		x++;
	return (x);
}

static int	ft_free_list(t_list123 *info, int ret)
{
	free(info->rem);
	free(info->tmp);
	free(info);
	return (ret);
}

static int	ft_new_line(char *buf, char **line, t_list123 *info)
{
	info->len = len_to_char(info->rem, '\0') + info->index;
	info->prev = 1;
	info->x = 0;
	info->y = 0;
	info->tmp = malloc((info->len * sizeof(char)) + 1);
	if (info->tmp == NULL)
		return (ft_free_list(info, -1));
	info->tmp[info->len] = '\0';
	if (info->rem != NULL)
	{
		while (info->rem[info->x] != '\0')
		{
			info->tmp[info->x] = info->rem[info->x];
			info->x++;
		}
		free (info->rem);
		info->rem = NULL;
	}
	while (buf[info->y] != '\n' && buf[info->y] != '\0')
	{
		info->tmp[info->x] = buf[info->y];
		info->x++;
		info->y++;
	}
	if (buf[info->y] == '\n')
	{
		info->len = len_to_char(buf + (info->y + 1), '\0');
		info->rem = malloc(sizeof(char) * info->len + 1);
		if (info->rem == NULL)
			return (ft_free_list(info, -1));
		info->rem[info->len] = '\0';
		info->x = 0;
		info->y++;
		while (buf[info->y] != '\0')
		{
			info->rem[info->x] = buf[info->y];
			info->y++;
			info->x++;
		}
		info->rem[info->x] = '\0';
	}
	*line = info->tmp;
	return (1);
}

static int	ft_null_byte(char *buf, t_list123 *info)
{
	info->x = len_to_char(buf, '\0');
	info->y = info->index + len_to_char(info->rem, '\0');
	info->tmp = malloc(sizeof(char) * info->y + 1);
	if (info->tmp == NULL)
		return (ft_free_list(info, -1));
	info->tmp[info->y] = '\0';
	while (info->y != 0 && info->x != 0)
	{
		info->y--;
		info->x--;
		info->tmp[info->y] = buf[info->x];
	}
	if (info->rem != NULL)
	{
		info->x = len_to_char(info->rem, '\0');
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

int	inti_list(t_list123 **info)
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
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static t_list123	*info = NULL;

	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!info)
		inti_list(&info);
	if (info == NULL)
		return (-1);
	info->x = 0;
	while (info->ret)
	{
		if (info->prev == 0)
		{
			info->ret = read(fd, buf, BUFFER_SIZE);
			buf[info->ret] = '\0';
			info->index = 0;
		}
		else
		{
			while (info->rem[info->x] != '\0')
			{
				buf[info->x] = info->rem[info->x];
				info->x++;
			}
			buf[info->x] = '\0';
			free (info->rem);
			info->rem = NULL;
			info->index = 0;
			info->prev = 1;
		}
		while (buf[info->index])
		{
			if (buf[info->index] == '\n')
			{
				ft_new_line(buf, line, info);
				info->index++;
				return (1);
			}
			info->index++;
		}
		if (buf[info->index] == '\0')
			ft_null_byte(buf, info);
	}
	return (0);
}
