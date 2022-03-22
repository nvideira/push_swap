/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_lots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:06:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/22 02:12:26 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	find_easiest(t_targs **stack_a, t_targs **stack_b)
{
	t_targs	*tempa;
	t_targs	*tempb;
	int		position_a;
	int		position_b;

	tempa = *stack_a;
	tempb = *stack_b;
	position_a = 1;
	position_b = 1;
	while (tempa->content < (*stack_b)->content && tempa != NULL)
	{
		tempa = tempa->next;
		position_a++;
	}
	while (tempb->content > (*stack_a)->content && tempb != NULL)
	{
		tempb = tempb->next;
		position_b++;
	}
}

int	largest(t_targs **stack)
{
	int		compare;
	t_targs	*temp;

	compare = (*stack)->content;
	temp = *stack;
	while (temp != NULL)
	{
		if (compare < temp->content)
			compare = temp->content;
		temp = temp->next;
	}
	return (compare);
}

int	third_largest(t_targs **stack)
{
	int		biggest;
	t_targs	*temp;
	int		compare;

	temp = *stack;
	biggest = largest(&(*stack));
	compare = 0;
	while (temp != NULL)
	{
		if (compare < temp->content && temp->content < biggest)
			compare = temp->content;
		temp = temp->next;
	}
	temp = *stack;
	if (compare != 0)
		biggest = compare;
	compare = 0;
	while (temp != NULL)
	{
		if (compare < temp->content && temp->content < biggest)
			compare = temp->content;
		temp = temp->next;
	}
	return (compare);
}

void	different_approach(t_targs **stack_a, t_targs **stack_b)
{
	while (stack_size(&(*stack_a)) > 3)
	{
		if ((*stack_a)->content < third_largest(&(*stack_a)))
			push(&(*stack_a), &(*stack_b), 'b')
	//	if (stack_size(&(*stack_b)) <= 1 || stack_size(&(*stack_a)) == 1)
	//		push(&(*stack_a), &(*stack_b), 'a');
	//	else
	//	{
	//		if ((*stack_a)->content > (*stack_b)->content)
	//			push(&(*stack_a), &(*stack_b), 'a');
	//		else
	//		{
	//			find_easiest(&(*stack_a), &(*stack_b));
	//		}
	//	}
	}
}
