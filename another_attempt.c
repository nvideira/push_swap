/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_attempt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:36:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/04/26 01:06:56 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

//int	ft_abs(int number)
//{
//	if (number < 0)
//		number *= -1;
//	return (number);
//}

//int	place_in_the_universe(int number, t_targs *stack)
//{
//	t_targs	*temp;
//	int		compare;
//	int		position;
//	int		location;

//	temp = stack;
//	position = 1;
//	location = 1;
//	compare = number - temp->content;
//	while (temp != NULL)
//	{
//		if (ft_abs(number - temp->content) < ft_abs(compare))
//		{
//			compare = number - temp->content;
//			location = position;
//		}
//		temp = temp->next;
//		position++;
//	}
//	return (location);
//}

//void	best_way(t_targs **stack_a, t_targs **stack_b)
//{
//	int		location_a;
//	int		location_b;
//	t_targs	*temp;

//	temp = *stack_b;
//	location_b = stack_size(stack_a);
//	while (temp != NULL)
//	{
//		if (location_b > place_in_the_universe(temp->content, *stack_a))
//			location_b = place_in_the_universe(temp->content, *stack_a);
//		temp = temp->next;
//	}
//}
int	find_in_stack(t_targs *stack, int n)
{
	int		position;
	t_targs	*temp;

	position = 1;
	temp = stack;
	while (temp != NULL && temp->content != n)
	{
		temp = temp->next;
		position++;
	}
	return (position);
}

int	arr_len(int *arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i + 1);
}

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

int	find_next_smallest(t_targs *stack, int ntb)
{
	int		compare;
	t_targs	*temp;

	compare = largest(stack);
	temp = stack;
	while (temp != NULL)
	{
		if (compare > temp->content && temp->content > ntb)
			compare = temp->content;
		temp = temp->next;
	}
	return (compare);
}

void	fill_array(int *org, t_targs *stack)
{
	unsigned int	i;
	int				ntb;
	unsigned int	size;

	i = 0;
	ntb = find_smallest(stack);
	size = stack_size(&stack);
	org[i] = ntb;
	i++;
	while (--size)
	{
		org[i] = find_next_smallest(stack, ntb);
		ntb = org[i];
		i++;
	}
	org[i] = '\0';
}

int	pos(int content, int *org)
{
	int	i;

	i = 0;
	while (org[i] && content != org[i])
		i++;
	return (i + 1);
}

int	calculate(t_targs *stack_a, t_targs *stack_b, int *org)
{
	t_targs	*temp;
	t_targs	*temp2;

	temp = stack_a;
	temp2 = stack_b;
	while (temp && pos(stack_b->content, org) > pos(temp->content, org))
		temp = temp->next;
	while (temp2 && pos(temp2->content, org) > pos(stack_a->content, org))
		temp2 = temp2->next;
	if (temp2 == NULL)
		return (2);
	if (find_in_stack(stack_a, temp->content) > stack_size(&stack_a) / 2)
	{
		if (find_in_stack(stack_b, temp2->content) > stack_size(&stack_b) / 2)
			return (1);
		return (2);
	}
	else
	{
		if (find_in_stack(stack_b, temp2->content) < stack_size(&stack_b) / 2)
			return (3);
		return (4);
	}
}

void	check_stack(t_targs **stack, int *org)
{
	t_targs	*temp;
	int		i;
	int		j;

	temp = *stack;
	i = find_in_stack(*stack, org[0]);
	j = 0;
	while (i-- > 1)
		temp = temp->next;
	while (j < stack_size(stack))
	{
		if (org[j] != temp->content)

		j++;
		if (temp->next != NULL)
			temp = temp->next;
		else
			while (temp->prev != NULL)
				temp = temp->prev;
	}
	if ((*stack)->content != org[0])
	{
		if (i > stack_size(stack) / 2)
		{
			while ((*stack)->content != org[0])
				rev_rot(stack, 'a');
		}
		else
		{
			while ((*stack)->content != org[0])
				rotate(stack, 'a');
		}
	}
}

void	sorting(t_targs **stack_a, t_targs **stack_b, int *org)
{
	int	i;

	i = 0;
	while (stack_size(stack_b) > 0)
	{
		if (pos((*stack_b)->content, org) < pos((*stack_a)->content, org))
			push(stack_b, stack_a, 'a');
		else
		{
			if (stack_size(stack_a) > 1 && (*stack_a)->next->content < (*stack_a)->content)
			{
				if (stack_size(stack_b) > 1 && (*stack_b)->next->content > (*stack_b)->content)
					swap_ss(stack_a, stack_b);
				else
					swap(stack_a, 'a');
			}
			else if (stack_size(stack_b) > 1 && (*stack_b)->next->content > (*stack_b)->content)
				swap(stack_b, 'b');
			else
			{
				if (calculate(*stack_a, *stack_b, org) == 1)
					rev_rot_rrr(stack_a, stack_b);
				else if (calculate(*stack_a, *stack_b, org) == 2)
					atop_bbot(stack_a, stack_b, org);
				else if (calculate(*stack_a, *stack_b, org) == 3)
					rotate_rr(stack_a, stack_b);			
				else
					abot_btop(stack_a, stack_b, org);
			}
		}
	}
	print_stack(*stack_a);
	if (!is_sorted(stack_a))
		big(stack_a, stack_b, 0);
	else
		check_stack(stack_a, org);
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
int	is_sorted(t_targs **stack)
{
	int		place;
	t_targs	*temp;
	int		j;
	
	place = find_small_position(stack);
	temp = *stack;
	j = 0;
	while (place-- > 1)
		temp = temp->next;
	while (j < stack_size(stack))
	{
		if (temp->next != NULL && temp->next->content < temp->content)
			return (0);
		if (temp->next == NULL && temp->content > (*stack)->content)
			return (0);
		if (temp->next == NULL)
		{
			while (temp->prev != NULL)
				temp = temp->prev;
		}
		else
			temp = temp->next;
		j++;
	}
	return (1);
}

void	big(t_targs **stack_a, t_targs **stack_b, int first)
{
	static int	*org;
	int	i;

	i = 0;
	if (first == 1)
	{
		org = malloc((stack_size(stack_a) + 1) * sizeof(int));
		fill_array(org, *stack_a);
	}
	while (stack_size(stack_a) > 3)
	{
		if (is_sorted(stack_a))
			break ;
		if ((*stack_a)->content >= third_largest(stack_a))
			rotate(stack_a, 'a');
		else
		{
			if (stack_size(stack_a) > 1 && (*stack_a)->next->content < (*stack_a)->content)
			{
				if (stack_size(stack_b) > 1 && (*stack_b)->next->content > (*stack_b)->content)
					swap_ss(stack_a, stack_b);
				else
					swap(stack_a, 'a');
			}
			else
				push(stack_a, stack_b, 'b');
		}
	}
	if (stack_size(stack_a) == 3)
		three_args(stack_a);
	sorting(stack_a, stack_b, org);
	//best_way(stack_a, stack_b);
	while (i < arr_len(org) - 1)
	{
		printf("%d - ", org[i]);
		i++;
	}
	free(org);
}
