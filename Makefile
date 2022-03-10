all: ascii-conv

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm ascii-conv

ascii-conv: ascii-conv.c
	$(CC) $(FLAGS) -o $@ $^
