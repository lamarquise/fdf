# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:24 by tlamart           #+#    #+#              #
#    Updated: 2019/06/26 14:50:17 by erlazo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

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

INC = -Iinclude
INCMLX = -I/usr/local/include

LIB_PATH = -Llibft
LIB = -lft

LIB_PATHMLX = -L/usr/local/lib
LIBMLX = -lmlx

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

do:
	gcc $(CFLAGS) src2/* -I inc/ ./lib/* -framework OpenGL -framework Appkit


$(NAME): $(OBJ)
	$(CC) $()
