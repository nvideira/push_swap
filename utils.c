/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:40:18 by nvideira          #+#    #+#             */
/*   Updated: 2022/04/18 18:29:04 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

//void	both_bot(t_targs **stack_a, t_targs **stack_b, int *org)
//{
//	t_targs	*temp;
//	t_targs	*temp2;

//	temp = stack_a;
//	temp2 = stack_b;
//	while (temp && pos((*stack_b)->content, org) > pos(temp->content, org))
//		temp = temp->next;
//	while (temp2 && pos(temp2->content, org) > pos((*stack_a)->content, org))
//		temp2 = temp2->next;
	
//}

//void	both_top(t_targs **stack_a, t_targs **stack_b)
//{

//}

void	atop_bbot(t_targs **stack_a, t_targs **stack_b, int *org)
{
	t_targs	*temp;
	t_targs	*temp2;

	temp = *stack_a;
	temp2 = *stack_b;
	while (temp->next != NULL && pos((*stack_b)->content, org) > pos(temp->content, org))
		temp = temp->next;
	while (temp2 && pos(temp2->content, org) > pos((*stack_a)->content, org))
		temp2 = temp2->next;
	if (temp2 == NULL)
		rotate(stack_a, 'a');
	else if ((stack_size(stack_b) - find_in_stack(temp2, temp2->content))
		- find_in_stack(temp, temp->content) > 0)
		rotate(stack_a, 'a');
	else
		rev_rot(stack_b, 'b');
}

void	abot_btop(t_targs **stack_a, t_targs **stack_b, int *org)
{
	t_targs	*temp;
	t_targs	*temp2;

	temp = *stack_a;
	temp2 = *stack_b;
	while (temp && pos((*stack_b)->content, org) > pos(temp->content, org))
		temp = temp->next;
	while (temp2 && pos(temp2->content, org) > pos((*stack_a)->content, org))
		temp2 = temp2->next;
	if (find_in_stack(temp2, temp2->content)
		- (stack_size(stack_a) - find_in_stack(temp, temp->content)) > 0)
		rev_rot(stack_a, 'a');
	else
		rotate(stack_b, 'b');
}
