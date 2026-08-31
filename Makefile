CC = gcc
NAME = mygrep

$(NAME): main.c
	$(CC) main.c -o $(NAME)

clean:
	rm -f $(NAME)