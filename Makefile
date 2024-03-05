NAME = libftprintf.a

SRCS = ft_printf.c\
	  ft_hexa.c\
	  ft_function.c\
	  ft_pntr.c\
	  ft_unsg.c

OBJS = $(SRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS) ft_printf.h
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
 
.PHONY : all clean fclean re
