/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_four_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:18:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/05 04:17:04 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	hi_five(t_targs **stack_a, t_targs **stack_b)
{
	int	position;

	while (stack_size(stack_a) > 3)
	{
		position = find_small_position(stack_a);
		if (position > stack_size(stack_a) / 2)
		{
			while (stack_size(stack_a) + 1 - position > 0)
			{
				rev_rot(stack_a, 'a');
				position++;
			}
		}
		else
		{
			while (position-- > 1)
				rotate(stack_a, 'a');
		}
		push(stack_a, stack_b, 'b');
	}
	three_args(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		swap(stack_b, 'b');
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}

void	do_four(t_targs **stack_a, t_targs **stack_b)
{
	int	position;

	position = find_small_position(stack_a);
	if (position == 2)
		rotate(stack_a, 'a');
	else if (position == 3)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (position == 4)
		rev_rot(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	three_args(stack_a);
	push(stack_b, stack_a, 'a');
}

void	three_args(t_targs **stack_a)
{
	if ((*stack_a)->next->next->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rev_rot(stack_a, 'a');
		else
		{
			rev_rot(stack_a, 'a');
			swap(stack_a, 'a');
		}
	}
	else if ((*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rotate(stack_a, 'a');
		else
			swap(stack_a, 'a');
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		swap(stack_a, 'a');
		rev_rot(stack_a, 'a');
	}
}
