# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:24 by tlamart           #+#    #+#              #
#    Updated: 2019/07/02 17:04:23 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src2/
SRC_NAME = ft_altitude.c \
ft_bresenham.c\
ft_color.c\
ft_draw.c\
ft_drawline.c\
ft_fdf.c\
ft_getfile.c\
ft_initfdf.c\
ft_keyhook.c\
ft_move.c\
ft_notbresenham.c\
ft_parser.c\
ft_perspective.c\
ft_projection.c\
ft_rotation.c\
ft_zoom.c\
main.c\


SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC = -I inc -I /usr/local/include

LIB_PATH = -L lib -L /usr/local/lib
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
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
