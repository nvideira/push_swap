/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:18:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/07 02:09:10 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	do_four(t_targs **stack_a, t_targs **stack_b)
{
	int	position;

	position = find_small(&(*stack_a));
	if (position == 2)
		rotate(&(*stack_a), 'a');
	else if (position == 3)
	{
		rotate(&(*stack_a), 'a');
		rotate(&(*stack_a), 'a');
	}
	else if (position == 4)
		rev_rot(&(*stack_a), 'a');
	push(&(*stack_a), &(*stack_b), 'a');
	three_args(&(*stack_a));
	push(&(*stack_b), &(*stack_a), 'b');
}

void	three_args(t_targs **stack_a)
{
	if ((*stack_a)->next->next->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rev_rot(&(*stack_a), 'a');
		else
		{
			rev_rot(&(*stack_a), 'a');
			swap(&(*stack_a), 'a');
		}
	}
	else if ((*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rotate(&(*stack_a), 'a');
		else
			swap(&(*stack_a), 'a');
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		swap(&(*stack_a), 'a');
		rev_rot(&(*stack_a), 'a');
	}
}

void	more_args(t_targs **stack_a, t_targs **stack_b)
{
	all_but_3(&(*stack_a), &(*stack_b));
	three_args(&(*stack_a));
	while (stack_size(&(*stack_b)) > 0)
	{
		push(&(*stack_b), &(*stack_a), 'b');
		print_stack(*stack_a);
	}
}
