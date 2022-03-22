/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:37:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/07 18:30:41 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	no_2_of_kind(char **arg)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 1;
	j = i + 1;
	while (arg[i + 1])
	{
		while (arg[j])
		{
			len = ft_strlen(arg[i]) + ft_strlen(arg[j]);
			if (ft_strncmp(arg[i], arg[j], len) == 0)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	is_int(char **arg)
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

int	not_big(char **arg)
{
	unsigned int	i;
	int				number;
	char			*back;

	i = 0;
	while (arg[++i])
	{
		number = ft_atoi(arg[i]);
		back = ft_itoa(number);
		if (ft_strncmp(arg[i], back, ft_strlen(arg[i])) != 0)
		{
			free(back);
			return (0);
		}
		free(back);
	}
	return (1);
}

int	check_inputs(char **arg)
{
	if (!is_int(&(*arg)))
		return (0);
	if (!no_2_of_kind(&(*arg)))
		return (0);
	if (!not_big(&(*arg)))
		return (0);
	return (1);
}
