/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:46:23 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/14 20:14:43 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	print_list(t_targs *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			printf("%d\n", lst->content);
		else
			printf("%d - ", lst->content);
		lst = lst->next;
	}
}
