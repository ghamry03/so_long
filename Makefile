# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 17:02:05 by ommohame          #+#    #+#              #
#    Updated: 2022/05/17 12:17:44 by ommohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	./srcs/manadtory/ft_map.c \
			./srcs/manadtory/so_long.c \
			./srcs/manadtory/ft_exit.c \
			./srcs/manadtory/ft_coin.c \
			./srcs/manadtory/ft_gate.c \
			./srcs/manadtory/ft_player.c \
			./srcs/manadtory/ft_big_map.c \
			./srcs/manadtory/ft_map_walls.c \
			./srcs/manadtory/ft_check_map.c \
			./srcs/manadtory/ft_map_check.c \
			./srcs/manadtory/ft_load_assets.c \
			./srcs/manadtory/ft_player_movement.c \
			./srcs/manadtory/ft_player_collision.c \
			./srcs/colors/ft_colors.c \

SRCS_B	=	./srcs/bonus/ft_map.c \
			./srcs/bonus/so_long.c \
			./srcs/bonus/ft_exit.c \
			./srcs/bonus/ft_coin.c \
			./srcs/bonus/ft_gate.c \
			./srcs/bonus/ft_player.c \
			./srcs/bonus/ft_big_map.c \
			./srcs/bonus/ft_map_walls.c \
			./srcs/bonus/ft_check_map.c \
			./srcs/bonus/ft_map_check.c \
			./srcs/bonus/ft_load_assets.c \
			./srcs/bonus/ft_player_movement.c \
			./srcs/bonus/ft_player_collision.c \
			./srcs/colors/ft_colors.c \
			./srcs/bonus/ft_jump.c \
			./srcs/bonus/ft_enemy.c \
			./srcs/bonus/ft_enemy_movement.c \

LIBFT_PATH	=	./Libft

LIBFT	=		./Libft/libft.a

FT_PRINT_F =	./ft_printf/libftprintf.a

FT_PRINT_F_PATH =	./ft_printf

MLX	=	./mlx/libmlx.a

MLX_PATH	=	./mlx

GET_NEXT_LINE = ./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \

CC		=	gcc

CFLAGS	= -Wall -Wextra -Werror -Ofast

MLX_FLAGS	=	-framework OpenGL -framework AppKit

RM		=	rm -rf

OBJS 	=	$(SRCS:.c=.o)

OBJS_B 	=	$(SRCS_B:.c=.o)

$(NAME)	:	$(OBJS)
			make -C $(LIBFT_PATH)
			make -C $(FT_PRINT_F_PATH)
			make -C $(MLX_PATH)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(FT_PRINT_F) $(GET_NEXT_LINE) $(MLX) -o $(NAME)

all		:	$(NAME)

bonus	:	$(OBJS_B)
			make -C $(LIBFT_PATH)
			make -C $(FT_PRINT_F_PATH)
			make -C $(MLX_PATH)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_B) $(LIBFT) $(FT_PRINT_F) $(GET_NEXT_LINE) $(MLX) -o $(NAME)


clean	:
			make clean -C $(LIBFT_PATH)
			make clean -C $(FT_PRINT_F_PATH)
			make clean -C ./mlx
			$(RM) $(OBJS) $(OBJS_B)

fclean	:	clean
			make fclean -C $(LIBFT_PATH)
			make fclean -C $(FT_PRINT_F_PATH)
			$(RM) $(NAME)

re		:	fclean all
 
reb	:	fclean bonus 

.PHONY	:	all clean fclean re

# OS := $(shell uname)
# ifeq (${OS},Darwin)
# 	MINILIBX	=	libmlx.a
# 	MLXFLAGS	= 	-framework OpenGL -framework AppKit ${MINILIBX}
# 	CFLAGS		+=	-D OSX
# else
# 	INC			=	%%%%
# 	INCLIB		=	$(INC)/../lib
# 	MINILIBX	=	libmlx.a
# 	MLXFLAGS 	=	-L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm
# 	CFLAGS		+=	-D LINUX
# endif

# NAME		=	so_long
# LIBFT		=	libft.a


# SSRCS		=		./srcs/bonus/ft_map.c \
# 			./srcs/bonus/so_long.c \
# 			./srcs/bonus/ft_exit.c \
# 			./srcs/bonus/ft_coin.c \
# 			./srcs/bonus/ft_gate.c \
# 			./srcs/bonus/ft_player.c \
# 			./srcs/bonus/ft_big_map.c \
# 			./srcs/bonus/ft_map_walls.c \
# 			./srcs/bonus/ft_check_map.c \
# 			./srcs/bonus/ft_map_check.c \
# 			./srcs/bonus/ft_load_assets.c \
# 			./srcs/bonus/ft_player_movement.c \
# 			./srcs/bonus/ft_player_collision.c \
# 			./srcs/colors/ft_colors.c \
# 			./srcs/bonus/ft_jump.c \
# 			./srcs/bonus/ft_enemy.c \
# 			./srcs/bonus/ft_enemy_movement.c \

# SOBJS		=	${SSRCS:.c=.o}

# CC			=	gcc
# CFLAGS		+=	-Wall -Wextra -Werror
# DEBUG		=	-g
# LIBC		=	ar rcs
# RM			=	rm -f


# ${NAME}:	mlibx
# 			${MAKE} all -C ./Libft
# 			$(MAKE) all -C ./ft_printf
# 			cp ./Libft/*.h ./include
# 			cp ./Libft/${LIBFT} .
# 			${CC} ${CFLAGS} ${DEBUG} ${SSRCS} ./ft_printf/libftprintf.a ./get_next_line/*.c ${LIBFT} ${MLXFLAGS} -o ${NAME} -I include

# all:		${NAME}

# mlibx:
# ifeq (${OS},Darwin)
# 			${MAKE} -C ./mlx
# 			cp ./mlx/${MINILIBX} ./
# else
# 			${MAKE} -C ./minilibx-linux
# 			cp ./minilibx-linux/${MINILIBX} /usr/local/lib
# 			cp ./minilibx-linux/*.h /usr/local/include
# endif

# libft:
# 			${MAKE} libft -C ./Libft
# 			cp ./Libft/includes/*.h ./include
# 			cp ./Libft/${LIBFT} .

# bonus:		all

# clean:
# 			${RM} ${OBJS}
# 			$(MAKE) clean -C ./Libft
# 			${MAKE} clean -C ./ft_printf


# fclean:		clean
# ifeq (${OS},Darwin)
# 			${RM} ${LIBFT} ${MINILIBX} ${NAME}
# else
# 			${RM} ${LIBFT} ./minilibx-linux/${MINILIBX} ${NAME}
# endif
# 			${MAKE} fclean -C ./Libft
# 			${MAKE} fclean -C ./ft_printf
# 			${MAKE} clean -C ./mlx

# re:			fclean all

# .PHONY : all libft bonus mlibx clean re fclean