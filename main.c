/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:16:52 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/21 02:30:19 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	main(int argc, char *argv[])
{
	unsigned int	i;
	t_targs			*stack_a;
	t_targs			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	if (argc <= 2)
		return (0);
	while (argc-- > 1)
		store_args(&stack_a, argv[i--]);
	print_list(stack_a);
	push_a(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	push_b(&stack_b, &stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("%d\n", stack_size(&stack_a));
	printf("%d\n", stack_size(&stack_b));
}
