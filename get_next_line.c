#include "get_next_line.h"

static t_list	*fr_create_list(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->ptr = 0;
	ft_memset(list->buf, 0, BUFF_SIZE);
	list->str = NULL;
	list->hold = NULL;
	list->next = NULL;
	return (new);
}

static char	*read_file(t_list *list)
{
	if (list->buf[list->ptr] == '\0')
	{
		list->ret = read(fd, list->buf, BUFF_SIZE);
		list->ptr = 0;
		if (list->ret < 0)
			return (NULL);
	}
	while (buf[list->ptr] != '\0')
	{
		if (list->buf[list->ptr] == '\n')
			return (ft_strjoin(list->str, (ft_strdup(list->buf, list->ptr)))); //we need to move ptr on increment farther!
		//	ft_stdup	code to skip newline
		if (list->buf[list->ptr] == '\0')
		{
			list->hold = list->str;
			list->str = ft_strjoin(list->buf, list->str);
			if (list->hold != NULL)
				free (list->hold);
			if (list->str == NULL)
				return (NULL);
			read_file(list);
		}
		list->ptr++;
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list		*ptr;
	char		*string;

	if (fd <= 0)
		return (ft_free_list(list, -1));
	if (!list)
		ft_create_list(fd);
	if (list == NULL)
		return (-1);
	while (fd != list->fd)
	{

	}
	string = read_file(list);
	if (string == NULL)
		return (ft_free_list(list, -1));
	if (list->buf[list->ptr] == '\n')
	{
		ft_memset(list->buf, 0, list->ptr);
		free (list->str);
		list->ptr++;
	}

	return (ret);
}
