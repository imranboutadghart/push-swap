CC=cc
CFLAGS= -Wextra -Wall -Werror# -O3
NAME= push_swap
BINDIR:=bin
SRC:=calculate_cost.c clear_b.c instructions1.c instructions3.c \
	least_cost.c mini_utils.c parsing.c realloc.c stack_implementation1.c\
	utils.c calculate_position.c free.c instructions2.c instructions.c\
	malloc.c original_free_malloc.c push_swap.c sort_3.c stack_implementation2.c
SRC:= $(filter-out free.c malloc.c, $(SRC))

OBJ:=$(patsubst %.c, $(BINDIR)/%.o,$(SRC))
VALGRIND_SRC:=$(filter-out original_free_malloc.c, $(wildcard *.c))
VALGRIND_OBJ:=$(patsubst %.c,$(BINDIR)/%.o,$(VALGRIND_SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(BINDIR)/%.o : %.c | $(BINDIR) 
	$(CC) $(CFLAGS) -o $@ -c $<

valgrind : $(VALGRIND_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(VALGRIND_OBJ)

debug : CFLAGS+=-g
debug : re
	gdb ./$(NAME)

clean :
	rm -rf $(BINDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

$(BINDIR) :
	mkdir -p $(BINDIR)

.PHONY : all clean fclean re debug valgrind echo
