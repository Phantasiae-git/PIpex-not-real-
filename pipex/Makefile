NAME_PROJECT = pipex
BONUS = pipexbonus

SRCS = pipex.c utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
LIBFT = Libft/libft.a

all: $(NAME_PROJECT)

.PHONY: all clean fclean re

$(NAME_PROJECT): $(OBJS)
	@make -C Libft/
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME_PROJECT)
	@echo  "$(CYAN)Build ($(NAME_PROJECT)): $(GREEN)[Success]$(RESET)"

%.o: %.c
	@cc -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make fclean -C Libft/
	@echo "$(YELLOW)Cleaned object files$(RESET)"

fclean: clean
	@rm -f $(NAME_PROJECT)
	@echo  "$(YELLOW)Cleaned $(CYAN)$(NAME_PROJECT): $(RED)[Success]$(RESET)"

re: fclean all

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED	= \033[1;31m
RESET = \033[0m