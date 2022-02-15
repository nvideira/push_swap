/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:16:52 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/14 20:25:21 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	main(int argc, char *argv[])
{
	unsigned int	i;
	t_targs			*lst;

	lst = NULL;
	i = argc - 1;
	if (argc <= 2)
		return (0);
	while (argc-- > 1)
	{
		store_args(&lst, argv[i--]);
	}
	print_list(lst);
}
