# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:36:32 by fcarlucc          #+#    #+#              #
#    Updated: 2023/11/14 18:08:15 by abuonomo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d

SRC = $(wildcard *.c) \
		$(wildcard map_build/*.c) \
		$(wildcard exit/*.c) \
		$(wildcard raycast/*.c) \
		$(wildcard init/*.c) \
		$(wildcard hook_handle/*.c) \
		$(wildcard engine/*.c) \

OBJS = $(SRC:.c=.o)

FLAGS :=-g

LIBFT_PATH = ./libft

MINILIBX_PATH = ./mlx_linux

LIBFT = ${LIBFT_PATH}/libft.a

MINILIBX =${MINILIBX_PATH}/libmlx.a

MINILIBX_LINUX =${MINILIBX_PATH}/libmlx_Linux.a

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -I/usr/includesude -Imlx_linux -c $< -o $@
	@echo "$(GREEN)$@ created!$(DEFAULT)"

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@make -C mlx_linux
	@cc $(FLAGS) $(OBJS) $(LIBFT) ${MINILIBX} ${MINILIBX_LINUX} -Lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LIN=1 -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@make clean -C mlx_linux
	@rm -f $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
