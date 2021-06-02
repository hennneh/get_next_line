all: get_next_line.c get_next_line_utils.c main.c
	gcc -O0 -Wall -Werror -Wextra -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c main.c
