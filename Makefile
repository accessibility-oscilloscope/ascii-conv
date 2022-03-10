all: ascii-conv reader

FLAGS = -g -Wall -Werror -std=c99

clean:
	rm ascii-conv reader

ascii-conv: ascii-conv.c
	$(CC) $(FLAGS) -o $@ $^

reader: reader.c
	$(CC) $(FLAGS) -o $@ $^
