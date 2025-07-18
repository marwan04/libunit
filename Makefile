NAME        := unit_tests
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Ilibft -Iframework

SRC_MAIN    := main.c
SRC_REAL    := real-tests/00-launcher.c real-tests/01-basic-test.c real-tests/02-empty-file.c
OBJ         := $(SRC_MAIN:.c=.o) $(SRC_REAL:.c=.o)

LIBFT_DIR   := libft
LIBUNIT_DIR := framework

LIBFT_LIB   := $(LIBFT_DIR)/libft.a
LIBUNIT_LIB := $(LIBUNIT_DIR)/libunit.a

.PHONY: all clean fclean re

all: $(LIBFT_LIB) $(LIBUNIT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBUNIT_LIB) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT_LIB):
	$(MAKE) -C $(LIBUNIT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBUNIT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBUNIT_DIR) fclean

re: fclean all

