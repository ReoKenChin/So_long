# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:13:36 by mcherki           #+#    #+#              #
#    Updated: 2022/03/19 15:48:47 by mcherki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

CC = gcc

SRC_M = Mandatory/so_long.c\
	Mandatory/check_map.c\
	Mandatory/draw.c\
	Mandatory/move_player.c\
	Mandatory/move.c\
	Mandatory/objects_check.c\
	Mandatory/read_map.c\
	Mandatory/split.c\
	Mandatory/init.c
	
SRC_B = Bonus/so_long.c\
	Bonus/check_map.c\
	Bonus/draw.c\
	Bonus/exit.c\
	Bonus/move_player.c\
	Bonus/move.c\
	Bonus/objects_check.c\
	Bonus/read_map.c\
	Bonus/split.c\
	Bonus/init.c
	
SRC_GNL = Mandatory/gnl/get_next_line.c

SRC_GNL_B = Bonus/gnl/get_next_line.c

CFLAGS = -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit

INC = Mandatory/so_long.h\
	Mandatory/ft_printf/ft_printf.h\
	Mandatory/gnl/get_next_line.h\

INC_B = Bonus/so_long_bonus.h\
	Bonus/ft_printf/ft_printf.h\
	Bonus/gnl/get_next_line.h\

SRC_PRINTF	= Mandatory/ft_printf/hex.c\
	Mandatory/ft_printf/nbr_str.c\
	Mandatory/ft_printf/printf.c\

SRC_PRINTF_B = Bonus/ft_printf/hex.c\
	Bonus/ft_printf/nbr_str.c\
	Bonus/ft_printf/printf.c\

OBJ_M	= $(SRC_M:.c=.o)

OBJ_B	= $(SRC_B:.c=.o)

OBJ_GNL	= $(SRC_GNL:.c=.o)

OBJ_GNL_B	= $(SRC_GNL_B:.c=.o)

OBJ_PRINTF_B = $(SRC_PRINTF_B:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF)
	$(CC) $(FLAGS) $(MLX) $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(OBJ_B) $(INC_B) $(OBJ_GNL_B) $(OBJ_PRINTF_B)
	$(CC) $(FLAGS) $(MLX) $(OBJ_B) $(OBJ_GNL_B) $(OBJ_PRINTF_B) -o $(NAME_B)

clean:
	@rm -rf $(OBJ_M) $(OBJ_GNL) $(OBJ_PRINTF)
	@rm -rf $(OBJ_B) $(OBJ_GNL_B) $(OBJ_PRINTF_B)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	
re: fclean all

.PHONY : re clean fclean all bonus