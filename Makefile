NAME = libftprintf.a

SRCS	= ./src/format_numbers.c \
		  ./src/format_strings.c \
		  ./src/format_others.c \
		  ./src/ft_printf.c \
		  ./src/librairy.c \
		  

OBJ	= $(SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
AR = ar crc

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all:	$(NAME)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re