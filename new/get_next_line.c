#include "get_next_line.h"
#include <stdio.h>

static char	*ft_write_to_line(char *ret, char **line, int bytes_read)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(ret))
	{
		*line = ft_substr(ret, 0, i);
		tmp = ft_substr(ret, i + 1, ft_strlen(ret));
		free(ret);
		ret = ft_strdup(tmp);
		free (tmp);
	}
	else if (bytes_read == 0)
	{
		*line = ret;
		ret = NULL;
	}
	return (ret);
}

static char	*ft_join_ret(char *buffer, char *ret)
{
	char	*tmp;

	if (ret)
	{
		tmp = ft_strjoin(ret, buffer);
		free(ret);
		ret = ft_strdup(tmp);
		free(tmp);
	}
	else
		ret = ft_strdup(buffer);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*ret;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while ((bytes_read))
	{
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		ret = ft_join_ret(buffer, ret);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read <= 0 && !ret)
	{
		*line = ft_strdup("");
		return (bytes_read);
	}
	ret = ft_write_to_line(ret, line, bytes_read);
	if (bytes_read <= 0 && !ret)
		return (bytes_read);
	return (1);
}
