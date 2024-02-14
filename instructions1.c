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

int	rotate_a(t_head *head, int print)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->a) <= 2)
		if (stack_size(head->a) <= 1 || swap_a(head, 1))
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
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(t_head *head, int print)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->b) <= 2)
		if (stack_size(head->b) <= 1 || swap_b(head, 1))
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
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int r_rotate_a(t_head *head, int print)
{
	t_stack	*tmp;
	
	if (stack_size(head->a) <= 2)
		if (stack_size(head->a) <= 1 || swap_a(head, 1))
			return (1);
	tmp = head->a;
	while(tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = head->a;
	head->a = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int r_rotate_b(t_head *head, int print)
{
	t_stack	*tmp;
	
	if (stack_size(head->b) <= 2)
		if (stack_size(head->b) <= 1 || swap_b(head, 1))
			return (1);
	tmp = head->b;
	while(tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = head->b;
	head->b = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}
