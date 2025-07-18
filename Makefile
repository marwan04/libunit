# Compiler and Flags
CC     := cc
CFLAGS := -Wall -Wextra -Werror

# Paths
REAL_TESTS := real-tests
FRAMEWORK  := framework
LIBFT      := libft

# Source files
MAIN    := main.c
TEST_OBJS := $(REAL_TESTS)/00-launcher.o $(REAL_TESTS)/01-basic-test.o

# Libs
LIBUNIT_A := $(FRAMEWORK)/libunit.a
LIBFT_A   := $(LIBFT)/libft.a

# Executable
NAME := unit_tests

all : $(NAME)
# Final link
$(NAME): $(MAIN) $(TEST_OBJS) $(LIBUNIT_A) $(LIBFT_A)
	$(CC) $(CFLAGS) -I$(REAL_TESTS) -I$(LIBFT) -o $@ $^


# Optional: build libft and framework
$(LIBFT_A):
	make -C $(LIBFT)

$(LIBUNIT_A):
	make -C $(FRAMEWORK)

# Clean rules
clean:
	rm -f $(TEST_OBJS)
	make -C $(LIBFT) fclean
	make -C $(FRAMEWORK) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

