all:
	clang --std=c11 -Wall -Werror -g -o bin/slambook src/slambook.c src/linked_list.c src/slambook_funcs.c
