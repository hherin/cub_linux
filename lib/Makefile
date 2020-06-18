CC	= gcc

RM	= rm -f

NAME	= libftprintf.a

MANDATORY =		./tools/ft_prftools.c\
				./tools/ft_unitoa_base.c\
				./tools/ft_itoahexa.c\
				./tools/ft_minmax.c\
				./src/type/ft_type_pourcent.c\
				./src/type/ft_type_c.c\
				./src/type/ft_type_d.c\
				./src/type/ft_type_p.c\
				./src/type/ft_type_s.c\
				./src/type/ft_type_u.c\
				./src/type/ft_type_x.c\
				./src/type/ft_type_xmaj.c\
				./src/ft_getopt.c\
				./src/ft_printf.c\
				./src/ft_struct_print.c\

MANDATORY_SRCS	=	${MANDATORY}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}


CFLAGS	= -g -Wall -Wextra -Werror

${NAME}: ${MANDATORY_OBJS}
			@echo "\033[32mmaking libft.a...\033[0m"
			@make -C ./lib/
			@cp ./lib/libft.a ./$(NAME)
			@echo "\033[32mmaking libftprintf...\033[0m"
			ar rc ${NAME} ${MANDATORY_OBJS}
			ranlib ${NAME}

all: ${NAME}

clean:
	@echo "\033[33mcleaning libftprintf repository...\033[0m"
	${RM} ${BONUS_OBJS} ${MANDATORY_OBJS}
	@make clean -C ./lib/

fclean: clean
	@echo "\033[33mremoving libftprintf library file...\033[0m"
	${RM} ${NAME}
	@make fclean -C ./lib/

re: fclean all bonus

.PHONY: all clean fclean re
