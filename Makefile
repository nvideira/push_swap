# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:26:46 by nvideira          #+#    #+#              #
#    Updated: 2022/02/14 20:07:41 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=	print_list.c\
			store_args.c\
			llist_functions.c\
			libft/ft_atoi.c

NAME=		libps.a
OBJECTS=	$(SOURCES:.c=.o)

CC=			gcc
CFLAGS=		-Wall -Werror -Wextra

all: $(NAME)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)
	gcc $(CFLAGS) main.c -L. -lps -o push_swap

norm:
	norminette ./*.c

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
