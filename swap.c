/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:11 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/02 21:29:05 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
	swap(&(*a), 0);
	swap(&(*b), 0);
	write(1, "ss\n", 3);
}
