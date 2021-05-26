#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char **test = "test";
	printf("buffer size = %d\n", BUFFER_SIZE);
	int	fd = open("file3", O_RDONLY);
	printf("fd = %d\n", fd);
	int a = get_next_line(fd, test);
	return (0);
}
