# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:24 by tlamart           #+#    #+#              #
#    Updated: 2019/07/02 02:39:33 by tlamart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src/
SRC_NAME = ft_altitude.c	\
		   ft_bresenham.c	\
		   ft_color.c		\
		   ft_draw.c		\
		   ft_drawline.c	\
		   ft_fdf.c			\
		   ft_getfile.c		\
		   ft_initfdf.c		\
		   ft_keyhook.c		\
		   ft_move.c		\
		   ft_notbresenham.c\
		   ft_parser.c		\
		   ft_projection.c	\
		   ft_zoom.c		\
		   main.c
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC = -I include -I /usr/local/include

LIB_PATH = -L libft -L /usr/local/lib
LIBFT = -lft
MLX = -lmlx
FW = -framework OpenGL -framework AppKit

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LIB_PATH) $(LIBFT) $(MLX) $(FW)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

