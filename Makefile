CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS_S =	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \

OBJS = $(SRCS_S:%.s=%.o)

NAME = libasm.a

%.o : %.s
	nasm -f elf64 -g $< -o $@
%.o : %.c
	$(CC) $(CFLAGS) -I. $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all

test: all
	$(CC) $(CFLAGS) -fsanitize=address -g3 test.c $(NAME) -I. -o test.out

test2: all
	$(CC) $(CFLAGS) -fsanitize=address -g3 test2.c $(NAME) -I. -o test.out


clean:
	$(RM) $(OBJS)
	$(RM) test.out

fclean: clean
	$(RM) $(NAME)

re: fclean all