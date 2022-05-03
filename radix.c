/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:18:43 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 04:45:32 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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

int	posi(int content, int *org)
{
	int	i;

	i = 0;
	while (content != org[i])
		i++;
	return (i);
}

void	radix(t_targs **s_a, t_targs **s_b, int *org, int size)
{
	int	i;
	int	j;
	int	max_bits;
	int	max_num;

	i = -1;
	max_num = size - 1;
	max_bits = 0;
	while (max_num >> max_bits != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((posi((*s_a)->content, org) >> i) & 1) == 1)
				rotate(s_a, 'a');
			else
				push(s_a, s_b, 'b');
		}
		while (stack_size(s_b) > 0)
			push(s_b, s_a, 'a');
	}
}
