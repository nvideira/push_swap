/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:25 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/06 23:38:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	push(t_targs **a, t_targs **b, char direction)
{
	t_targs	*old;

	if (stack_size(&(*a)) == 0)
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
	lst_add_front(&(*b), old);
	if (direction == 'a')
		write(1, "pa\n", 3);
	else if (direction == 'b')
		write(1, "pb\n", 3);
}
