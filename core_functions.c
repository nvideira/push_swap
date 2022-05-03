/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:30 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 04:40:29 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
