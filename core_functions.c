/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:30 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/28 20:38:05 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	store_args(t_targs **lst, char *arg)
{
	int		number;

	number = ft_atoi(arg);
	lst_add_front(&(*lst), ft_new_node(number));
}

int	stack_size(t_targs **stk)
{
	unsigned int	count;
	t_targs			*temp;

	temp = *stk;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
