CC=cc
CFLAGS= -Wextra -Wall #-Werror -O3
NAME= push_swap
SRC:= $(wildcard *.c)
OBJ:=$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
