/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_lots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:06:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/04/12 10:24:11 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*very unefficient! don't use this!*/

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

int	largest(t_targs *stack)
{
	int		compare;
	t_targs	*temp;

	compare = stack->content;
	temp = stack;
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
	biggest = largest(*stack);
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

//void	different_approach(t_targs **stack_a, t_targs **stack_b)
//{
//	int	position;

//	while (stack_size(&(*stack_b)) <= 1)
//	{
//		if ((*stack_a)->content < third_largest(&(*stack_a)))
//			push(&(*stack_a), &(*stack_b), 'b');
//		else
//			rotate(&(*stack_a), 'a');
//	}
//	while (stack_size(&(*stack_a)) > 3)
//	{
//		if ((*stack_a)->content >= third_largest(&(*stack_a)))
//			rotate(&(*stack_a), 'a');
//		else if ((*stack_a)->content > (*stack_b)->content)
//		{
//			if ((*stack_a)->next->content < (*stack_a)->content
//				&& (*stack_a)->next->content > (*stack_b)->content)
//				swap(&(*stack_a), 'a');
//			else if (what_last(*stack_b) > (*stack_b)->content
//				&& (*stack_a)->content > what_last(*stack_b))
//				rev_rot(stack_b, 'b');
//			else
//				push(&(*stack_a), &(*stack_b), 'b');
//		}
//		else if ((*stack_a)->content < find_smallest(&(*stack_b)))
//		{
//			position = find_small_position(&(*stack_b));
//			if (position < stack_size(stack_b) / 2)
//			{
//				while (position--)
//					rotate(stack_b, 'b');
//			}
//			else
//			{
//				while (position++ < stack_size(stack_b))
//					rev_rot(stack_b, 'b');
//			}
//			push(stack_a, stack_b, 'b');
//			rotate(stack_b, 'b');
//		}
//		else if ((*stack_b)->content < (*stack_b)->next->content
//			&& (*stack_a)->content < (*stack_a)->next->content)
//			swap_ss(&(*stack_a), &(*stack_b));
//		else if ((*stack_b)->content < (*stack_b)->next->content)
//			swap(&(*stack_b), 'b');
//		else if ((*stack_a)->content < (*stack_a)->next->content
//			&& (*stack_a)->next->content < third_largest(&(*stack_a)))
//			swap(&(*stack_a), 'a');
//		else if ((*stack_a)->content < (*stack_b)->content
//			&& (*stack_a)->next->content > (*stack_b)->content
//			&& (*stack_a)->next->content < third_largest(&(*stack_a)))
//			rotate(&(*stack_a), 'a');
//		else if ((*stack_a)->content < (*stack_b)->content
//			&& what_last(*stack_a) > (*stack_b)->content
//			&& what_last(*stack_a) < third_largest(&(*stack_a)))
//			rev_rot(&(*stack_a), 'a');
//		else if ((*stack_a)->content < (*stack_b)->content
//			&& (*stack_a)->content > (*stack_b)->next->content
//			&& (*stack_a)->content < third_largest(&(*stack_a)))
//			rotate(&(*stack_b), 'b');
//		else if ((*stack_a)->content < (*stack_b)->content
//			&& (*stack_a)->content > what_last(*stack_b))
//			rev_rot(&(*stack_b), 'b');
//		else
//		{
//			while ((*stack_b)->content > (*stack_a)->content)
//				rotate(stack_b, 'b');
//			push(stack_a, stack_b, 'b');
//		}
//		//print_stack(*stack_b);
//		//sleep(2);
//		//print_stack(*stack_a);
//	}
//	while (what_last(*stack_b) > (*stack_b)->content)
//		rev_rot(stack_b, 'b');
//	//print_stack(*stack_b);
//	//sleep(2);
//	three_args(&(*stack_a));
//	//print_stack(*stack_a);
//	while (stack_size(&(*stack_b)) > 0)
//		push(stack_b, stack_a, 'a');
//	//print_stack(*stack_a);
//}
