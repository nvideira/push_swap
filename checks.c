/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:37:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/24 21:56:22 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	check_inputs(char **arg)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 0;
	while (arg[i])
	{
		if (arg[i][j] == '+' || arg[i][j] == '-' ||
			(arg[i][j] >= '0' && arg[i][j] <= '9'))
			j++;
		else
			return (0);
		while (arg[i][j] != '\0')
		{
			if (arg[i][j] >= '0' && arg[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
