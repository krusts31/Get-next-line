#include "get_next_line.h"
#include <stdio.h>

static	char	*ft_free(char **buf)
{
	if (buf == NULL)
		return (NULL);
	if (**buf == '\0')
		return (NULL);
	if (*buf != NULL)
	{
	//	printf("fail4\n");
		free(*buf);
	//	printf("fail4\n");
		*buf = NULL;
	}
	return (NULL);
}

static int	ft_byts_till_new_line(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\n')
		index++;
	return (index);
}

static int	ft_process_line(char **dest, char *src)
{
	int	i;
	int	index;

	i = 0;
	index = ft_byts_till_new_line(src);
//	printf("this si index: %d\n", index);
	if (index == 0)
	{

//		printf("fail3\n");
//		printf("this is buf: |%s|\n", src);
//		printf("this is a quick test: ||");
		src = ft_free(&src);
//		printf("fail3\n");
//		printf("proces line ret -42\n");
		return (-42);
	}
	*dest = ft_calloc(index + 1, sizeof(char));
	if (*dest == NULL)
		return (-1);
	if (src == NULL)
	{
//		printf("proces line ret -42\n");
		return (-42);
	}
	while (src[i] != '\0' && index > -1)
	{
		if (src[i] == '\n' && ft_strlen(dest[0]) > 0)
		{
//			printf("proces line ret ftstrlen (\\n)\n");
			return ((int) ft_strlen(dest[0]));
		}
		if (src[i] == '\0')
		{
//			printf("proces line ret (\\0)\n");
			return ((int) ft_strlen(dest[0]));
		}
		dest[0][i] = src[i];
//		printf("RUNES ONLY ONE TIME!  %d  \n", i);
		i++;
		index--;
	}
//	printf("proces line ret (dest[0])\n");
	return ((int) ft_strlen(dest[0]));
}

static char	*ft_cut_buf(char **buf)
{
	int	index;
	char	*ptr;
	int	i;

	i = 0;
	index = ft_byts_till_new_line(*buf);
	if (index == 0)
		return ("Done");
	ptr = ft_calloc(ft_strlen(*buf), sizeof(char));
	if (ptr == NULL)
		return (ft_free(buf));
	while (buf[0][i + index] != '\0')
	{
		ptr[i] = buf[0][i + index];
		i++;
	}
	if (i == 0)
	{
//		printf("fail\n");
		free(ptr);
//		printf("fail\n");
		ptr = NULL;
	}
//	printf("fail1\n");
	
	ft_free(buf);
//	printf("fail1\n");
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	static	char		*buf;
	int			index;

	index = 0;
	if (buf)
	{
//		printf("LAST LOOP if\n");
		index = ft_process_line(line, buf);
		if (ft_strlen(buf) != 0)
			buf = ft_cut_buf(&buf); //returns -42 when end of file
		if (index != -42 && *line)
		{
		//	printf("\n1DOBE1\n");
			return ((int)ft_strlen(line[0]));
		}
	}
	else
	{
//		printf("LAST LOOP\n");
		buf = ft_calloc(BUFF_SIZE + 1, sizeof(char));
		if (buf == NULL)
			return (-1);
		if (read(fd, buf, BUFF_SIZE) == -1)
			return (-1);
		index = ft_process_line(line, buf);
		if (index == -1)
			return (-1);
		if (index != -42 && *line)
		{
		//	printf("\nDOBE\n");
			return (ft_strlen(*line));
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	ret;

	char	*line;


	fd = 0;
	i = 1;
	ret = 1;
	if (argc <= 1)
	{
		printf("%s\n", "Pass some more arguemnts");
		return (0);
	}

	while(argc > 1)
	{
		fd = open(argv[i], O_RDONLY);
		while(ret > 0)
		{
			line = NULL;
			ret = get_next_line(fd, &line);
			if (ret > -1 && line != NULL && *line != '\0')
			{
				write(1, line, ft_strlen(line));
				write(1, "\n", sizeof(char));
			}
//			printf("ret: %d\n", ret);
			if (line != NULL)
				free(line);
		}
		i++;
		argc--;
	}
	return (0);
}
