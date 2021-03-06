/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:18:14 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/06 19:14:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nuno;

	nuno = malloc(sizeof(t_list));
	if (!nuno)
		return (NULL);
	nuno->content = content;
	nuno->next = NULL;
	return (nuno);
}
