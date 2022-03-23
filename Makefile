# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:26:46 by nvideira          #+#    #+#              #
#    Updated: 2022/03/23 05:43:47 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=	print_list.c\
			core_functions.c\
			llist_functions.c\
			swap.c\
			push.c\
			rotate.c\
			revrot.c\
			main.c\
			checks.c\
			algorithm.c\
			redo_lots.c

NAME=		push_swap
OBJECTS=	$(SOURCES:.c=.o)

LIBFT=		Libft/libft.a
LIBFT_DIR=	libft
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 43 2 1
	
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
