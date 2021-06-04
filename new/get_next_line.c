#include "get_next_line.h"

static char	*ft_line(char *buff, char **line, int readcount)
{
	unsigned int	i;
	char			*str;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(buff))
	{
		*line = ft_substr(buff, 0, i);
		str = ft_substr(buff, i + 1, ft_strlen(buff));
		free(buff);
		buff = ft_strdup(str);
		free (str);
	}
	else if (readcount == 0)
	{
		*line = buff;
		buff = NULL;
	}
	return (buff);
}

static char	*ft_join(char *temp, char *buff)
{
	char	*str;

	if (buff)
	{
		str = ft_strjoin(buff, temp);
		free(buff);
		buff = ft_strdup(str);
		free(str);
	}
	else
		buff = ft_strdup(temp);
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff;
	char		temp[BUFFER_SIZE + 1];
	int			readcount;

	readcount = read(fd, temp, BUFFER_SIZE);
	while ((readcount))
	{
		if (readcount == -1)
			return (-1);
		temp[readcount] = '\0';
		buff = ft_join(temp, buff);
		if (ft_strchr(temp, '\n'))
			break ;
		readcount = read(fd, temp, BUFFER_SIZE);
	}
	if (readcount < 1 && !buff)
	{
		*line = ft_strdup("");
		return (readcount);
	}
	buff = ft_line(buff, line, readcount);
	if (readcount <= 0 && !buff)
		return (readcount);
	return (1);
}
