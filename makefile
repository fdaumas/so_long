#SETUP
NAME    =   so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3
#CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

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
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -L minilibx -lmlx -o $(NAME) && DYLD_LIBRARY_PATH=minilibx
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I minilibx -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY:	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
