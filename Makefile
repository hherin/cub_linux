# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hherin <hherin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 20:38:20 by hherin            #+#    #+#              #
#    Updated: 2020/06/10 14:59:27 by hherin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

CC		=	gcc

RM		=	rm -rf

DIR_S	=	.

DIR_O	=	./tmp

LIB	=	./lib

SOURCES	=	parcing/error/check_error.c\
			parcing/error/quit.c\
			parcing/error/error_map.c\
			parcing/parcing.c\
			parcing/file_struct.c\
			parcing/tab_parcing.c\
			parcing/init_parcing.c\
			parcing/utils.c\
			parcing/utils2.c\
			parcing/direction.c\
			src/event.c\
			src/window.c\
			src/move.c\
			src/raycasting.c\
			src/save.c\
			src/texture.c\
			src/sprite.c\
			src/utils_sprite.c\
			src/final.c\
			src/ceil_and_floor.c\
			src/minimap.c\
			main.c


SRC		=	$(addprefix $(DIR_S)/,$(SOURCES))

OBJ		=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEAD	=	./inc/

INC		=	-I ${HEAD}

CFLAGS	=	-Wall -Wextra -Werror -O3

MLX_FLAG =	-lz -L ./inc/mlx -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${DIR_O}/%.o: ${DIR_S}/%.c
	@mkdir -p tmp
	@mkdir -p tmp/parcing/error
	@mkdir -p tmp/src
	${CC} ${CFLAGS} ${INC} -o $@ -c $<

${NAME} : ${OBJ}
	@make -C ${LIB}
	@make -C ./inc/mlx
	${CC} ${CFLAGS} ./lib/libftprintf.a ${OBJ} ./inc/mlx/libmlx.a ${MLX_FLAG} -o $@

clean:
	${RM} ${DIR_O}
	@make clean -C ${LIB}
	@make clean -C ./inc/mlx/

fclean: clean
	${RM} ${NAME}
	@make fclean -C ${LIB}

re: fclean all

.PHONY: all clean fclean re
