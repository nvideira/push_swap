/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:46:23 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/20 20:13:12 by nvideira         ###   ########.fr       */
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

void	print_stack(t_targs *lst)
{
	printf("---\n");
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("___\n");
}

void	print_back(t_targs *lst)
{
	t_targs	*index;

	index = lst_last(lst);
	while (index != NULL)
	{
		if (index->prev == NULL)
			printf("%d\n", index->content);
		else
			printf("%d - ", index->content);
		index = index->prev;
	}
}
