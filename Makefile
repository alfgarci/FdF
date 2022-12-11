# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:35:22 by alfgarci          #+#    #+#              #
#    Updated: 2022/12/11 16:04:57 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=\033[1;31m
GREEN	=\033[1;32m
YELLOW	=\033[1;33m
NC		=\033[0m

#---fdf---------------------------------
NAME 	=	fdf
	#---SRC
SRC_DIR	=	src
SRC 	=	${SRC_DIR}/main.c \
			${SRC_DIR}/check_map.c \
			${SRC_DIR}/print.c \
			${SRC_DIR}/init_data.c \
			${SRC_DIR}/bresenham.c \
			${SRC_DIR}/utils.c \
			${SRC_DIR}/moves.c \
			${SRC_DIR}/color.c
	#---OBJ
OBJ 	=	${SRC:.c=.o}
	#---INC
INC 	=	includes

#---LIBFT-------------------------------
LIBFT_DIR	=	libft
LIBFT_NAME	=	ft
	#---INC
LIBFT_INC	= ${LIBFT_DIR}/includes

#---MLX---------------------------------
MLX_DIR		=	mlx
MLX_NAME	=	mlx
MLX_LIB		=	lib${MLX_NAME}.a
	#---INC
MLX_INC		=	${MLX_DIR}

#---MATH--------------------------------
MATH_NAME	=	m

CC			=	cc
C_FLAGS		=	-Werror -Wextra -Wall
LIB_FLAGS	=	-L${LIBFT_DIR} -l${LIBFT_NAME} \
				-L${MLX_DIR} -l${MLX_NAME} \
				-l${MATH_NAME}
H_FLAGS		=	-I${INC} -I${LIBFT_INC} -I${MLX_INC}
FW_FLAGS	=	-framework OpenGL -framework AppKit
FLAGS		=	${C_FLAGS} ${FW_FLAGS} ${LIB_FLAGS}

#---RECIPES------------------------------
%.o : %.c
	@${CC} ${H_FLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJ}
		@echo "${RED}Compiling Libft...${NC}"
		@make -s -C ${LIBFT_DIR}
		@echo "${RED}Compiling MLX...${NC}"
		@make -s -C ${MLX_DIR}
		@echo "${RED}Compiling FdF...${NC}"
		@${CC} ${FLAGS} ${OBJ} -o ${NAME}
		@echo "${GREEN}${NAME} READY!${NC}"

clean:
		@make clean -s -C ${LIBFT_DIR}
		@rm -f ${OBJ}
		@echo "${YELLOW}OBJS REMOVED!${NC}"

fclean:		clean
		@make fclean -s -C ${LIBFT_DIR}
		@make clean -s -C ${MLX_DIR}
		@rm -f ${NAME}
		@echo "${YELLOW}${NAME} REMOVED!${NC}"

re:		fclean all
		@make re -s -C ${MLX_DIR}

n:
	@norminette src/ libft/

.PHONY:	all clean fclean re
