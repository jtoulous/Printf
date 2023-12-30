NAME = libftprintf.a

SRC = ft_printf.c toolbox.c

CFLAGS = -Wall -Wextra -Werror -c

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME) 
	
$(NAME) :$(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(SRC:.c=.o)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
