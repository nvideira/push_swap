# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:26:46 by nvideira          #+#    #+#              #
#    Updated: 2022/05/05 03:50:18 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=	main.c\
			checks.c\
			core_functions.c\
			llist_functions.c\
			push_and_swap.c\
			rotates.c\
			three_four_five.c\
			radix.c\

NAME=		push_swap
OBJECTS=	$(SOURCES:.c=.o)

LIBFT=		Libft/libft.a
LIBFT_DIR=	libft
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -g

all: $(NAME)
	
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) $(LIBFT)
	@echo "\033[93mPreparing to push and swap...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	@echo "\033[93mMaking Libft\033[0m"
	@make -s -C $(LIBFT_DIR)
	@echo "\033[92mLibft compiled!\033[0m"

norm:
	norminette ./*.c

debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SOURCES) $(LIBFT)
	
valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes\
		./$(NAME) -498 -381 496 668 -187 186 0 711 827 -896 -60 833 -62 854
	
clean:
	@rm -f $(OBJECTS)
	@make -s clean -C $(LIBFT_DIR)

fclean:	clean
	@echo "\033[091mRemoving EVERYTHING, but the essentials!\033[0m"
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@rm -fR push_swap.dSYM

re:	fclean all

.PHONY: all norm clean fclean re
