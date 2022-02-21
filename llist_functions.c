/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:12:44 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/21 20:01:30 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_targs	*ft_new_node(int content)
{
	t_targs	*node;

	node = (t_targs *)malloc(sizeof(t_targs));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	lst_add_front(t_targs **lst, t_targs *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
	}
	*lst = new;
}

t_targs	*lst_last(t_targs *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_targs **lst, t_targs *new)
{
	t_targs	*help;

	if (*lst == NULL)
		*lst = new;
	else
	{
		help = lst_last(*lst);
		help->next = new;
		new->prev = help;
	}
}

void	lstdelone(t_targs *lst, void (*del)(int))
{
	del(lst->content);
	free(lst);
}
