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

NAME = cub3D

SRC = $(wildcard *.c) \
		$(wildcard map_build/*.c) \
		$(wildcard exit/*.c) \
		#$(wildcard raycast/*.c) \

OBJS = $(SRC:.c=.o)

FLAGS := -g

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

AZZURRO = \033[1;34m


all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
