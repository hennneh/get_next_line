all: get_next_line.c get_next_line_utils.c main.c
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c
