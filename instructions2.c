/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/07 23:05:07 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_head *head)
{
	write(1, "pa\n", 3);
	push(&head->a, pop(&head->b));
	return (1);
}

int	push_b(t_head *head)
{
	write(1, "pb\n", 3);
	push(&head->b, pop(&head->a));
	return (1);
}

int	swap_a(t_head *head)
{
	void	*tmp;
	
	tmp = head->a->data;
	head->a->data = head->a->next->data;
	head->a->next->data = tmp;
	write(1, "sa\n", 3);
	return (1);
}

int	swap_b(t_head *head)
{
	void	*tmp;
	
	tmp = head->b->data;
	head->b->data = head->b->next->data;
	head->b->next->data = tmp;
	write(1, "sb\n", 3);
	return (1);
}
