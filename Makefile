NAME        := unit_tests
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Ilibft -Iframework

SRC_MAIN    := main.c
SRC_REAL    := real-tests/00_launcher.c real-tests/01_basic_test.c real-tests/02_empty_file.c \
	       real-tests/03_strcpy_basic.c real-tests/04_strcpy_empty.c \
	       real-tests/05_ft_strncmp_equal.c real-tests/06_ft_strncmp_different.c \
	       real-tests/07_ft_atoi_basic.c real-tests/08_ft_atoi_negative.c real-tests/09_ft_atoi_invalid.c \


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

