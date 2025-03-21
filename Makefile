NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = so_long.c pars.c
DEPS = inc/so_long.h
ODIR = obj/
OBJ = $(SRC:%.c=$(ODIR)%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = ./minilibx-linux

.PHONY: all clean fclean re libft_comp mlx_comp

all: libft_comp mlx_comp $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@echo "compiling so_long 🧙"
	@$(CC) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

libft_comp :
	@$(MAKE) -s -C $(LIBFT_DIR)

mlx_comp :
	@$(MAKE) -s -C $(MLX_DIR)

$(ODIR)%.o: src/%.c Makefile $(DEPS) | $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "clean all obj🔮"
	@rm -rf $(ODIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean

fclean: clean
	@echo "remove exe 🍄"
	@rm -rf $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean

re: fclean all