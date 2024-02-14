CC=cc
CFLAGS= -Wextra -Wall #-Werror -O3
NAME= push_swap
BINDIR:=bin
SRC:= $(filter-out original_free_malloc.c, $(wildcard *.c))
OBJ:=$(patsubst %.c, $(BINDIR)/%.o,$(SRC))
VALGRIND_SRC:=$(filter-out free.c malloc.c, $(wildcard *.c))
VALGRIND_OBJ:=$(patsubst %.c,$(BINDIR)/%.o,$(VALGRIND_SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(BINDIR)/%.o : %.c | $(BINDIR) 
	$(CC) $(CFLAGS) -o $@ -c $<

valgrind : $(VALGRIND_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(VALGRIND_OBJ)

echo :
	@echo [NAME]"\n"$(NAME)"\n"
	@echo [SRC]"\n"$(SRC)"\n"
	@echo [OBJ]"\n"$(OBJ)"\n"
	@echo [VALGRIND_SRC]"\n"$(VALGRIND_SRC)"\n"
	@echo [VALGRIND_OBJ]"\n"$(VALGRIND_OBJ)"\n"
	@echo [BINDIR]"\n"$(BINDIR)"\n"
	

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
