/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/07 23:05:25 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_head *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->a) <= 2)
		if (stack_size(head->a) <= 1 || swap_a(head))
			return (1);
	tmp = head->a;
	head->a = head->a->next;
	tmp->next = NULL;
	tmp2 = head->a;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	put_instruction(RA);
	return (1);
}

int	rotate_b(t_head *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->b) <= 2)
		if (stack_size(head->b) <= 1 || swap_b(head))
			return (1);
	tmp = head->b;
	head->b = head->b->next;
	tmp->next = NULL;
	tmp2 = head->b;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	put_instruction(RB);
	return (1);
}

int r_rotate_a(t_head *head)
{
	t_stack	*tmp;
	
	if (stack_size(head->a) <= 2)
		if (stack_size(head->a) <= 1 || swap_a(head))
			return (1);
	tmp = head->a;
	while(tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = head->a;
	head->a = tmp->next;
	tmp->next = NULL;
	put_instruction(RRA);
	return (1);
}

int r_rotate_b(t_head *head)
{
	t_stack	*tmp;
	
	if (stack_size(head->b) <= 2)
		if (stack_size(head->b) <= 1 || swap_b(head))
			return (1);
	tmp = head->b;
	while(tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = head->b;
	head->b = tmp->next;
	tmp->next = NULL;
	put_instruction(RRB);
	return (1);
}
