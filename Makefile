# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:11:47 by pausanch          #+#    #+#              #
#    Updated: 2023/11/30 14:54:24 by pausanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS	= -Wall -Werror -Wextra
RM = rm -f
MLX_FLAGS = -Llibft -lft -LMLX -lmlx -framework OpenGL -framework AppKit


SRC_DIR = sources/
SRC	=	draw.c exit_game.c game.c init.c map_validate.c player_update.c read_map.c so_long.c
OBJ_DIR = sources/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


BONUS_NAME = bonus
BONUS_SRC_DIR = sources_bonus/
BONUS_SRC = utils_bonus.c draw_bonus.c animation_bonus.c exit_game_bonus.c game_bonus.c init_bonus.c map_validate_bonus.c player_update_bonus.c read_map_bonus.c so_long_bonus.c
BONUS_OBJ_DIR = sources_bonus/
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:.c=.o))


MLX		= ./MLX/libmlx.a
LIBFT	= ./libft/libft.a


all:	$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
		@gcc $(OBJS) $(MLX_FLAGS) -o $(NAME)
		@echo "So_long compilado!"


bonus: $(NAME_BONUS)
	
$(NAME_BONUS): $(BONUS_OBJ) $(MLX) $(LIBFT)
		@gcc $(BONUS_OBJ) $(MLX_FLAGS) -o $(NAME_BONUS)
		@echo "Bonus compilado"

		
$(MLX):
		@make -C ./mlx
		@echo "MLX compilado"

$(LIBFT):
		@make -C ./libft
		@echo "Libft compilado"

.c.o:
		@clang $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		@rm -rf $(OBJS) $(BONUS_OBJ) $(MLX) $(LIBFT)
		@make -C ./libft clean
		@echo "Limpiando todo..."

libclean:
		@make -C ./mlx clean
		@make -C ./libft fclean

fclean:	clean
		@rm -rf $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: clean fclean re all libclean .c.o bonus