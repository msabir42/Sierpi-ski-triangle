CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = sierpinski_triangle
SRC =  main.c utils.c  triangle.c 
OBJS = $(SRC:.c=.o)
LIBS = libmlx.a -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
