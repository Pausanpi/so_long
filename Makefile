# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 16:48:41 by pausanch          #+#    #+#              #
#    Updated: 2023/11/03 15:58:42 by pausanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SOURCE	=	draw.c \
			exit_game.c \
			game.c \
			init.c \
			map_validate.c \
			player_update.c \
			read_map.c \
			so_long.c \
			wall_texture.c

OBJS	= $(addsuffix .o, $(notdir $(basename $(SOURCE))))
#OBJS	= ${SOURCE:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -Imlx -c

MLX		= ./MLX/libmlx.a

LIBFT	= ./libft/libft.a


all:	bonus

bonus:	$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
		gcc $(OBJS) -Llibft -lft -LMLX -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Ejecutable listo!"

$(MLX):
		@make -C ./mlx
		@echo "Libreria mala"

$(LIBFT):
		@make -C ./libft
		@echo "Libft * ~ *"

.c.o:	$(SOURCE)
		gcc $(CFLAGS) -c $(SOURCE)
		@echo "Objetos objetacionados"

clean:
		@rm -rf $(OBJS)
		@echo "Limpiando todo..."

libclean:
		@make -C ./mlx clean
		@make -C ./libft clean

fclean:	clean
		@rm -rf ${NAME}

re:	clean all

.PHONY: clean fclean re all libclean .c.o bonus