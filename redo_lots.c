/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_lots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:06:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/23 06:05:24 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

//void	find_easiest(t_targs **stack_a, t_targs **stack_b)
//{
//	t_targs	*tempa;
//	t_targs	*tempb;
//	int		position_a;
//	int		position_b;

//	tempa = *stack_a;
//	tempb = *stack_b;
//	position_a = 1;
//	position_b = 1;
//	while (tempa->content < (*stack_b)->content && tempa != NULL)
//	{
//		tempa = tempa->next;
//		position_a++;
//	}
//	while (tempb->content > (*stack_a)->content && tempb != NULL)
//	{
//		tempb = tempb->next;
//		position_b++;
//	}
//}

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
		while (stack_size(&(*stack_b)) <= 1)
		{
			if ((*stack_a)->content < third_largest(&(*stack_a)))
				push(&(*stack_a), &(*stack_b), 'b');
			else
				rotate(&(*stack_a), 'a');
		}
		if ((*stack_a)->content >= third_largest(&(*stack_a)))
			rotate(&(*stack_a), 'a');
		else if ((*stack_b)->content < (*stack_b)->next->content
			&& (*stack_a)->content > (*stack_a)->next->content)
			swap_ss(&(*stack_a), &(*stack_b));
		else if ((*stack_b)->content < (*stack_b)->next->content)
			swap(&(*stack_b), 'b');
		else if ((*stack_a)->content > (*stack_a)->next->content)
			swap(&(*stack_a), 'a');
		else if ((*stack_a)->content > (*stack_b)->content
			&& (*stack_a)->content < what_last(*stack_b))
			push(&(*stack_a), &(*stack_b), 'b');
		else
		{
			if ((*stack_a)->content > (*stack_b)->next->content
				&& (*stack_a)->content < (*stack_b)->content)
				rotate(&(*stack_b), 'b');
			else if (what_last(*stack_a) > (*stack_b)->content
				&& what_last(*stack_a) < what_last(*stack_b))
				rev_rot(&(*stack_a), 'a');
			else if ((*stack_a)->next->content > (*stack_b)->next->content
				&& (*stack_a)->next->content < (*stack_b)->content)
				rotate_rr(&(*stack_a), &(*stack_b));
			else if (what_last(*stack_a) > what_last(*stack_b)
				&& lst_last(*stack_b)->prev->content > what_last(*stack_a))
				rev_rot_rrr(&(*stack_a), &(*stack_b));
			else if ((*stack_a)->content > what_last(*stack_b)
				&& (*stack_a)->content < lst_last(*stack_b)->prev->content)
				rev_rot(&(*stack_b), 'b');
			else
				push(&(*stack_a), &(*stack_b), 'b');
		}
	}
	three_args(&(*stack_a));
	while (stack_size(&(*stack_b)) > 0)
		push(&(*stack_b), &(*stack_a), 'a');
}
/*KO*/
