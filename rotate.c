/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:33 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/21 20:45:00 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(t_targs **a)
{
	t_targs	*new;
	t_targs	*end;

	if (stack_size(&(*a)) <= 1)
		return ;
	new = *a;
	end = lst_last(*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	new->prev = end;
	end->next = new;
	new->next = NULL;
	//write(1, "ra\n", 3);
}

//void	rotate_b(t_targs **b)
//{
//	t_targs	*new;
//	t_targs	*end;

//	if (stack_size(&(*b)) <= 1)
//		return ;
//	new = *b;
//	end = lst_last(*b);
//	*b = (*b)->next;
//	(*b)->prev = NULL;
//	new->prev = end;
//	end->next = new;
//	new->next = NULL;
//	write(1, "rb\n", 3);
//}

//void	rotate_rr(t_targs **a, t_targs **b)
//{
//	write(1, "rr\n", 3);
//}
