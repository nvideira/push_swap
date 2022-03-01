# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:26:46 by nvideira          #+#    #+#              #
#    Updated: 2022/02/28 21:40:16 by nvideira         ###   ########.fr        #
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
			few_args.c

NAME=		push_swap
OBJECTS=	$(SOURCES:.c=.o)

LIBFT=		Libft/libft.a
LIBFT_DIR=	libft
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra

all: $(NAME)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

norm:
	norminette ./*.c

debug:
	$(CC) -g $(CFLAGS) -o $(NAME) $(SOURCES) $(LIBFT) && lldb $(NAME) 1 3 2
	
valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 25 36 52 85 79 654 254 -125 4521 -5425
	
clean:
	rm -f $(OBJECTS)
	make -s clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	make -s fclean -C $(LIBFT_DIR)
	rm -fR push_swap.dSYM

re:	fclean all

.PHONY: all norm clean fclean re
