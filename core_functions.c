/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:30 by nvideira          #+#    #+#             */
/*   Updated: 2022/04/03 23:32:53 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	find_smallest(t_targs *stack)
{
	int		compare;
	t_targs	*temp;

	compare = stack->content;
	temp = stack;
	while (temp != NULL)
	{
		if (compare > temp->content)
			compare = temp->content;
		temp = temp->next;
	}
	return (compare);
}

int	find_small_position(t_targs **stack)
{
	int		compare;
	int		position;
	int		ret;
	t_targs	*temp;

	compare = (*stack)->content;
	position = 1;
	temp = *stack;
	ret = 0;
	while (temp != NULL)
	{
		if (compare > temp->content)
		{
			compare = temp->content;
			ret = position;
		}
		temp = temp->next;
		position++;
	}
	return (ret);
}

int	stack_size(t_targs **stk)
{
	unsigned int	count;
	t_targs			*temp;

	temp = *stk;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	all_but_3(t_targs **stack_a, t_targs **stack_b)
{
	int	position;

	while (stack_size(&(*stack_a)) > 3)
	{
		position = find_small_position(&(*stack_a));
		if (position > stack_size(&(*stack_a)) / 2)
		{
			while ((stack_size(&(*stack_a)) - position + 2) > 1)
			{
				rev_rot(&(*stack_a), 'a');
				position++;
			}
		}
		else
		{
			while (position > 1)
			{
				rotate(&(*stack_a), 'a');
				position--;
			}
		}
		push(&(*stack_a), &(*stack_b), 'b');
	}
}
