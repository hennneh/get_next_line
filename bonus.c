#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		check;

	fd = open("file1", O_RDONLY);
	check = 1;
	while (check > 0)
	{
		check = get_next_line(fd, &line);
		if (check > 0)
			printf("%s\n", line);
	}
	fd = open("file2", O_RDONLY);
	check = 1;
	while (check > 0)
	{
		check = get_next_line(fd, &line);
		if (check > 0)
			printf("%s\n", line);
	}
	fd = open("file3", O_RDONLY);
	check = 1;
	while (check > 0)
	{
		check = get_next_line(fd, &line);
		if (check > 0)
			printf("%s\n", line);
	}
	return (0);
}
