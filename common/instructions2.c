/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:59:03 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_head *head, int print)
{
	if (!head->b)
		my_exit(ko());
	push(&head->a, pop(&head->b));
	++(head->size_a);
	--(head->size_b);
	if (print)
		put_instruction(PA);
	return (1);
}

int	push_b(t_head *head, int print)
{
	if (!head->a)
		my_exit(ko());
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

	if (!head->a)
		my_exit(ko());
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

	if (!head->b)
		my_exit(ko());
	tmp = head->b->data;
	head->b->data = head->b->next->data;
	head->b->next->data = tmp;
	if (print)
		put_instruction(SB);
	return (1);
}
