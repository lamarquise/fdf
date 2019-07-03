# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:24 by tlamart           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/07/03 16:05:21 by erlazo           ###   ########.fr        #
=======
#    Updated: 2019/07/02 16:54:42 by erlazo           ###   ########.fr        #
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82
#                                                                              #
# **************************************************************************** #

NAME = fdf

<<<<<<< HEAD
SRC_PATH = src/
SRC_NAME = ft_altitude.c		\
		   ft_bresenham.c		\
		   ft_color.c			\
		   ft_draw.c			\
		   ft_drawline.c		\
		   ft_drawtools.c		\
		   ft_fdf.c				\
		   ft_getfile.c			\
		   ft_initfdf.c			\
		   ft_keyhook.c			\
		   ft_move.c			\
		   ft_notbresenham.c	\
		   ft_parser.c			\
		   ft_perspective.c		\
		   ft_projection.c		\
		   ft_rotation.c		\
		   ft_rotations_tools.c	\
		   ft_zoom.c			\
		   main.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
=======
SRC_PATH = src
SRC_NAME = main.c			\
		   ft_get_file.c	\
		   ft_parser.c		\
		   ft_fdf.c			\
		   ft_initfdf.c		\
		   ft_draw.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82

INC = -Iinclude
INCMLX = -I/usr/local/include

<<<<<<< HEAD
INC = -I include -I /usr/local/include
HEADER = include/fdf.h
LIB_PATH = -L libft -L /usr/local/lib
LIB = -lft -lmlx -lm
FW = -framework OpenGL -framework AppKit
=======
LIB_PATH = -Llibft
LIB = -lft

LIB_PATHMLX = -L/usr/local/lib
LIBMLX = -lmlx
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

<<<<<<< HEAD
$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $@ $^ $(LIB_PATH) $(LIB) $(FW)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make clean -C libft
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
=======
do:
	gcc  src2/* -I inc/ ./lib/* -framework OpenGL -framework Appkit


$(NAME): $(OBJ)
	$(CC) $()
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82
