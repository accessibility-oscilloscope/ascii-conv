all: ascii_conv

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm ascii_conv

ascii_conv: ascii_conv.c
	gcc $(FLAGS) -o $@ $^
