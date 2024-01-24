NAME = so_long
CC = cc

SRC = 	window.c \
		map_checker.c \
		map_checker1.c \
		map_checker2.c \
		path_finder.c \
		mlx_handler.c \

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME):$(OBJ)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx-linux
	$(CC) $(SRC) -Wall -Werror -Wextra -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -o $(NAME)

clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf
fclean: clean
	rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
re: fclean all
