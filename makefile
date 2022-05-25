# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdaumas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 15:47:15 by fdaumas           #+#    #+#              #
#    Updated: 2022/05/25 19:32:58 by fdaumas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME    =   so_long
CC		=	gcc
CC_FLAGS    = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit 
RM		=	rm -rf
MAKE	=	make

# FILE & PATH
HEADER	=	./so_long.h src/get_next_line/get_next_line.h
SRCS	=	main.c\
			convert_file.c\
			fileformat.c\
			map_verif.c\
			free.c moove.c\
			print.c\
			src/ft_split.c\
			src/ft_strnstr.c\
			src/ft_putnbr.c\
			src/get_next_line/get_next_line.c\
			src/get_next_line/get_next_line_utils.c
LMLX    = mlx/libmlx.dylib
OBJS	=	$(SRCS:.c=.o)

all: makemlx $(NAME)

$(NAME): $(OBJS) 
	$(CC) ${OBJS} ${CC_FLAGS} -o $(NAME) 
	@echo	"$(GREEN)$(NAME) created!$(DEFAULT)"
	@cp mlx/libmlx.dylib .

%.o: %.c $(SRCS) $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(LMLX): makemlx

makemlx:
	@${MAKE} -C mlx/
	@cp mlx/libmlx.dylib .

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libmlx.dylib
	@$(MAKE) clean -C mlx/ 
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY:	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
