/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:18:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/28 21:42:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	three_args(t_targs **stack_a)
{
	if ((*stack_a)->next->next->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rev_rot(&(*stack_a));
		else
		{
			rev_rot(&(*stack_a));
			swap(&(*stack_a));
		}
	}
	else if ((*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rotate(&(*stack_a));
		else
			swap(&(*stack_a));
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		swap(&(*stack_a));
		rev_rot(&(*stack_a));
	}
}

void	five_args(t_targs **stack_a, t_targs **stack_b)
{
	
}
