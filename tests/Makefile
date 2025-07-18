# **************************************************************************** #
#                                  LIBUNIT TESTS                               #
# **************************************************************************** #

NAME    = unit_test
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I../framework

# Paths
SRC_DIR = strlen

# Source files
SRC     = ../framework/libunit.c \
          main.c \
          $(SRC_DIR)/00_launcher.c \
          $(SRC_DIR)/01_ok_test.c \
          $(SRC_DIR)/02_ko_test.c \
          $(SRC_DIR)/03_segv_test.c \
          $(SRC_DIR)/04_bus_test.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

test: all
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
