

# a makefile that handles inclues and library seperately

NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OTH		=	-framework OpenGL -framework Appkit
LIBS	=	libft.a -L /usr/local/lib/ -lmlx

SRCS	=	test.c		\
		=	draw_line.c	\
		=	toolz_1.c	\

OBJS	=	$(SRCS:%.c=%.o)


.PHONY	= all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $? $(CFLAGS) $(LIBS) $(OTH)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

