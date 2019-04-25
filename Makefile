

# a makefile that handles inclues and library seperately

NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OTH		=	-framework OpenGL -framework Appkit
LIBS	=	libft.a -L /usr/local/lib/ -lmlx

SRCS	=	main.c		\
			projector.c	\
			linear_transformations.c	\


.PHONY	= all fclean re

all:
	$(CC) -o $(NAME) $(CFLAGS) -I ./inc ./funcs/* ./lib/* $(SRCS) $(OTH)

fclean:
	rm -f $(NAME)

re: fclean all

