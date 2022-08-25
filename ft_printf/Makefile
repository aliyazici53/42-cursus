NAME=	libftprintf.a

SRC=	ft_printf.c ft_printf_writers.c

OBJS=	$(SRC:.c=.o)

CC=		@gcc

CFLAGS=	-Wall -Wextra -Werror -I.

RM=		@rm -rf

all: 	$(NAME)

$(NAME): $(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo ➤ Archiving was successful.

clean:
			$(RM) $(OBJS)
			@echo ➤ Deleting was successful.

fclean: clean
			$(RM) $(NAME)
			@echo ➤ Archive name was successful.

re:	fclean $(NAME)
			@echo ➤ Archiving was successful.
		
.PHONY=	all re clean fclean 