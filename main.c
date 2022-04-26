/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:16:52 by nvideira          #+#    #+#             */
/*   Updated: 2022/04/24 23:55:21 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	begin_alg(int *argc, t_targs **stack_a, t_targs **stack_b)
{
	if (*argc == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, 'a');
	}
	else if (*argc == 4)
		three_args(stack_a);
	else if (*argc == 5)
		do_four(stack_a, stack_b);
	else
		big(stack_a, stack_b, 1);
}

void	store_args(t_targs **lst, char *arg)
{
	int		number;

	number = ft_atoi(arg);
	lst_add_front(&(*lst), ft_new_node(number));
}

int	main(int argc, char *argv[])
{
	unsigned int	i;
	t_targs			*stack_a;
	t_targs			*stack_b;
	int				arghelp;

	stack_a = NULL;
	stack_b = NULL;
	arghelp = argc;
	i = argc - 1;
	if (argc <= 2)
		return (0);
	if (!check_inputs(&(*argv)))
		return (write(1, "Error", 5));
	while (arghelp-- > 1)
		store_args(&stack_a, argv[i--]);
	begin_alg(&argc, &stack_a, &stack_b);
	while (stack_a != NULL)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}
