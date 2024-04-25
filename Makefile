CC:=cc
CFLAGS:= -Wextra -Wall -Werror -I.# -O3
NAME:= push_swap
BNAME:= checker

.DEFAULT_GOAL := $(NAME)

BINDIR:=bin
MANDIR:=mandatory
BONDIR:=bonus
COMMONDIR:=common

COMMONSRC:= instructions1.c instructions2.c instructions3.c utils1.c utils2.c\
			parsing.c stack_implementation1.c stack_implementation2.c instructions.c\
			free.c malloc.c
MSRC:=	to_array.c clear_b.c \
		sort_3_5.c push_swap.c
BSRC:= checker.c get_next_line.c get_next_line_utils.c
MOBJ:=$(patsubst %.c, $(BINDIR)/%.o,$(MSRC) $(COMMONSRC))
BOBJ:=$(patsubst %.c, $(BINDIR)/%.o,$(BSRC) $(COMMONSRC))
vpath %.c $(MANDIR) $(BONDIR) $(COMMONDIR)

all : $(NAME) $(BNAME)

$(NAME) : $(MOBJ)
	$(CC) $(CFLAGS) -o $@ $(MOBJ)

$(BNAME) : $(BOBJ)
	$(CC) $(CFLAGS) -o $@ $(BOBJ)

$(BINDIR)/%.o : %.c | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

debug : CFLAGS+=-g
debug : fclean all

clean :
	rm -rf $(BINDIR)

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : fclean $(NAME)

bonus : $(BNAME)

$(BINDIR) :
	mkdir -p $(BINDIR)

.PHONY : all clean fclean re debug valgrind echo bonus
.SECONDARY: