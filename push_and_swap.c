/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:25 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 04:06:30 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	push(t_targs **a, t_targs **b, char direction)
{
	t_targs	*old;

	if (stack_size(a) == 0)
		return ;
	old = *a;
	if ((*a)->next != NULL)
	{
		*a = (*a)->next;
		(*a)->prev = NULL;
	}
	else
		*a = NULL;
	old->next = NULL;
	old->prev = NULL;
	lst_add_front(b, old);
	if (direction == 'b')
		write(1, "pb\n", 3);
	else if (direction == 'a')
		write(1, "pa\n", 3);
}

void	swap(t_targs **a, char stack)
{
	int	helper;

	helper = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = helper;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

void	swap_ss(t_targs **a, t_targs **b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}
