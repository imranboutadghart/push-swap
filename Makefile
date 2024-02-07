CC=cc
CFLAGS= -Wextra -Wall #-Werror -O3
NAME= push_swap
SRC:= $(wildcard *.c)
OBJ:=$(patsubst %.c,bin/%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
bin/%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
debug : CFLAGS+=-g
debug : re
	gdb ./$(NAME)

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)

.PHONY : all clean fclean re debug
