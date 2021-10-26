# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:24 by tlamart           #+#    #+#              #
#    Updated: 2019/07/02 16:54:42 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

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

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC = -I include -I /usr/local/include
HEADER = include/fdf.h
LIB_PATH = -L libft -L /usr/local/lib
LIB = -lft -lmlx -lm
FW = -framework OpenGL -framework AppKit


CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

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
