CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS_S = ft_strlen.s

OBJS = $(SRCS_S:%.s=%.o)

NAME = libasm.a

%.o : %.s
	nasm -f macho64 -g $< -o $@
%.o : %.c
	$(CC) $(CFLAGS) -I. $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)


test: all
	$(CC) $(CFLAGS) -fsanitize=address -g3 test.c $(NAME) -I. -o test.out

clean:
	$(RM) $(OBJS)
	$(RM) test.out

fclean: clean
	$(RM) $(NAME)

re: fclean all