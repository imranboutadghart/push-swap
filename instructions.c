/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/06 17:36:55 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_head *head)
{
	write(1, "pa\n", 3);
	push(&head->a, pop(&head->b));
}

void	push_b(t_head *head)
{
	write(1, "pb\n", 3);
	push(&head->b, pop(&head->a));
}

void	rotate_a(t_head *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->a) <= 2)
	{
		//if (stack_size(head->a) == 1 || swap_a(head));
		return ;
	}
	tmp = head->a;
	head->a = head->a->next;
	tmp->next = NULL;
	tmp2 = head->a;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_head *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stack_size(head->b) <= 2)
	{
		//if (stack_size(head->a) == 1 || swap_a(head));
		return ;
	}
	tmp = head->b;
	head->b = head->b->next;
	tmp->next = NULL;
	tmp2 = head->b;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	write(1, "rb\n", 3);
}