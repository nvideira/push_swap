/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:42 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/16 19:25:09 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rev_rot_a(t_targs **a)
{
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_targs **b)
{
	write(1, "rrb\n", 4);
}

void	rev_rot_rr(t_targs **a, t_targs **b)
{
	write(1, "rrr\n", 4);
}
