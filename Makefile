NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = so_long.c
DEPS = inc/so_long.h
ODIR = obj/
OBJ = $(SRC:%.c=$(ODIR)%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re libft_comp

all: libft_comp $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@echo "compiling so_long 🧙"
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

libft_comp :
	@$(MAKE) -s -C $(LIBFT_DIR)

$(ODIR)%.o: src/%.c Makefile $(DEPS) | $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "clean all obj🔮"
	@rm -rf $(ODIR)
	@$(MAKE) -s -C ./libft clean

fclean: clean
	@echo "remove exe 🍄"
	@rm -rf $(NAME)
	@$(MAKE) -s -C ./libft fclean

re: fclean all
