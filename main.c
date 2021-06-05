#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		a;

	printf("buffer size = %d\n", BUFFER_SIZE);
	fd = open("file4", O_RDONLY);
	printf("fd = %d\n", fd);
	a = 1;
	while (a > 0)
	{
		a = get_next_line(fd, &line);
		if (a > 0)
			printf("%s\n", line);
	}
}
