/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:18:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/05 17:55:24 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	three_args(t_targs **stack_a)
{
	if ((*stack_a)->next->next->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rev_rot(&(*stack_a), 'a');
		else
		{
			rev_rot(&(*stack_a), 'a');
			swap(&(*stack_a), 'a');
		}
	}
	else if ((*stack_a)->next->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			rotate(&(*stack_a), 'a');
		else
			swap(&(*stack_a), 'a');
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		swap(&(*stack_a), 'a');
		rev_rot(&(*stack_a), 'a');
	}
}

//void	more_args(t_targs **stack_a, t_targs **stack_b)
//{
//}
