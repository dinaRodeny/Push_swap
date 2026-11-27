NAME = push_swap
PROJECT_DIR = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
LIBFT = $(PROJECT_DIR)libft/libft.a
PRINTF_DIR = $(PROJECT_DIR)printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(PROJECT_DIR)libs

SRC = algo_adaptive.c \
	bench_setup.c \
	benchmark.c \
	create_stack.c \
	disorder.c \
	errorhandling.c \
	main.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	sorting.c \
	stack_utils.c \
	swap.c

OBJ = $(addprefix $(PROJECT_DIR), $(SRC:.c=.o))
TARGET = $(PROJECT_DIR)$(NAME)

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $@

$(PROJECT_DIR)%.o: $(PROJECT_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(PROJECT_DIR)libft

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PROJECT_DIR)libft clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(TARGET)
	$(MAKE) -C $(PROJECT_DIR)libft fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

RM = rm -f

.PHONY: all clean fclean re
