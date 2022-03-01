/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:37:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/28 21:29:15 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	no_2_of_kind(char **arg)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = i + 1;
	while (arg[i + 1])
	{
		while (arg[j])
		{
			if (ft_strncmp(arg[i], arg[j], ft_strlen(arg[i])) == 0)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

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
	if (!no_2_of_kind(&(*arg)))
		return (0);
	return (1);
}
