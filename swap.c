/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:11 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/27 23:45:04 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	swap(t_targs **a)
{
	int	helper;

	helper = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = helper;
	write(1, "sa\n", 3);
}

//void	swap_b(t_targs *b)
//{
//	int	helper;

//	helper = b->next->content;
//	b->next->content = b->content;
//	b->content = helper;
//	write(1, "sb\n", 3);
//}

//void	swap_ss(t_targs *a, t_targs *b)
//{
//	int	helper;

//	helper = a->next->content;
//	a->next->content = a->content;
//	a->content = helper;
//	helper = b->next->content;
//	b->next->content = b->content;
//	b->content = helper;
//	write(1, "ss\n", 3);
//}
