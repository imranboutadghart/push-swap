/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/26 16:18:58 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_head *head, int print)
{
	if (!head->size_b)
		return (1);
	push(&head->a, pop(&head->b));
	++(head->size_a);
	--(head->size_b);
	if (print)
		put_instruction(PA);
	return (1);
}

int	push_b(t_head *head, int print)
{
	if (!head->size_a)
		return (1);
	push(&head->b, pop(&head->a));
	--(head->size_a);
	++(head->size_b);
	if (print)
		put_instruction(PB);
	return (1);
}

int	swap_a(t_head *head, int print)
{
	void	*tmp;

	if (head->size_a < 2)
		return (1);
	tmp = head->a->data;
	head->a->data = head->a->next->data;
	head->a->next->data = tmp;
	if (print)
		put_instruction(SA);
	return (1);
}

int	swap_b(t_head *head, int print)
{
	void	*tmp;

	if (head->size_b < 2)
		return (1);
	tmp = head->b->data;
	head->b->data = head->b->next->data;
	head->b->next->data = tmp;
	if (print)
		put_instruction(SB);
	return (1);
}
