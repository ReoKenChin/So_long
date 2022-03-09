CC = gcc

CFLAGS = -Wall -Wextra -Werror 

AR     = ar rcs

NAME = so_long

SRC	= so_long.c check_map.c ft_split.c get_next_line.c gnl/get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

%.o:%.c 
	@$(CC) $(CFLAGS) -c $< -o so_long

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $?

clean:
	@rm -rf ${OBJ}

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY : re clean fclean all

