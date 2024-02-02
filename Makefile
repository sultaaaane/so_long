NAME = so_long
BNAME = so_long_bonus
CC = cc

SRC = 	map_checker.c \
		map_checker1.c \
		map_checker2.c \
		path_finder.c \
		mlx_handler.c \
		mlx_handler1.c \
		player.c \
		player1.c \


SRC_BONUS = map_checker_bonus.c \
		map_checker1_bonus.c \
		map_checker2_bonus.c \
		path_finder_bonus.c \
		mlx_handler_bonus.c \
		mlx_handler1_bonus.c \
		player_bonus.c \
		player1_bonus.c \

OBJ = $(SRC:.c=.o)
BOBJ = $(SRC_BONUS:.c=.o)
all: $(NAME) 
bonus: $(BNAME)

$(NAME):$(OBJ)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx-linux
	$(CC) $(SRC) -Wall -Wextra -Werror -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -o $(NAME)

$(BNAME):$(BOBJ)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx-linux
	$(CC) $(SRC_BONUS) -Wall -Wextra -Werror -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -o $(BNAME)
clean:
	rm -rf $(OBJ) $(BOBJ)
	@make clean -C libft
	@make clean -C ft_printf
fclean: clean
	rm -rf $(NAME) $(BNAME)
	@make fclean -C libft
	@make fclean -C ft_printf
re: fclean all
