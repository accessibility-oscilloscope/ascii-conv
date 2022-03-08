all: convert ascii_conv

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm convert

conver: convert.c
	gcc $(FLAGS) -o $@ $^

ascii_conv: ascii_conv.c
	gcc $(FLAGS) -o $@ $^
