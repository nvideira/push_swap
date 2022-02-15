/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:30 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/14 19:06:45 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	store_args(t_targs **lst, char *arg)
{
	int		number;

	number = ft_atoi(arg);
	lst_add_front(&(*lst), ft_new_node(number));
}
