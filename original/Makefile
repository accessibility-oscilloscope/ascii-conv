all: convert

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm convert

convert: convert.c
	gcc $(FLAGS) -o $@ $^
