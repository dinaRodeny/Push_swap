# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/17 21:49:47 by user              #+#    #+#              #
#    Updated: 2026/11/16 16:46:49 by delroudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#complilador 
NAME = push_swap
LIBFT = libft.a
PRINTF = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libs


SRC = create_stack.c\
	 main.c\
	 errorhandling.c\
	 push.c\
	 swap.c\
	 rotate.c\
	 rev_rotate.c\
	 sorting.c\
	

OBJ = $(SRC:.c=.o)


RM = rm -f
AR = ar rcs

#Default Rule
all: $(NAME)

#implict rule fpor compiling
#cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


#ar -rcs libft.a *.o
# Package library
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

# Clean object files
clean:
	$(RM) $(OBJ)

# Clean all
fclean: clean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

 # Phony targets (They are not real files)
.PHONY: all clean fclean re