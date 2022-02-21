/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:25 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/21 20:42:53 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	push(t_targs **a, t_targs **b)
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
	//write(1, "pa\n", 3);
}

//void	push_b(t_targs **b, t_targs **a)
//{
//	t_targs	*old;

//	if (stack_size(&(*b)) == 0)
//		return ;
//	old = *b;
//	if ((*b)->next != NULL)
//	{
//		*b = (*b)->next;
//		(*b)->prev = NULL;
//	}
//	else
//		*b = NULL;
//	old->next = NULL;
//	old->prev = NULL;
//	lst_add_front(&(*a), old);
//	write(1, "pb\n", 3);
//}
