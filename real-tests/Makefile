# Makefile inside real-tests/

NAME = tester

SRCS = main.c 00-launcher.c 01-basic-test.c 02-empty-file.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I../framework -I../libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBUNIT = ../framework/libunit.a
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBUNIT):
	make -C ../framework

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBUNIT) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C ../framework clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ../framework fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

