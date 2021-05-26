#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	printf("%d\n", BUFFER_SIZE);
	int	fd = open("file1", O_RDONLY);
	int df = open("file2", O_RDONLY);
	printf("%d\n", fd);
	printf("%d\n", df);
	return (0);
}
