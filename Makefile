all: convert

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm convert

conver: convert.c
	gcc $(FLAGS) -o $@ $^