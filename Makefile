NAME	=	philo

SRC		=	philo.c \
			action.c \
			mutexInit.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wextra -Wall -lpthread

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
