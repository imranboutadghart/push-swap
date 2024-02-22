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
	push(&head->a, pop(&head->b));
	put_instruction(PA);
	return (1);
}

int	push_b(t_head *head)
{
	push(&head->b, pop(&head->a));
	put_instruction(PB);
	return (1);
}

int	swap_a(t_head *head)
{
	void	*tmp;
	
	tmp = head->a->data;
	head->a->data = head->a->next->data;
	head->a->next->data = tmp;
	put_instruction(SA);
	return (1);
}

int	swap_b(t_head *head)
{
	void	*tmp;
	
	tmp = head->b->data;
	head->b->data = head->b->next->data;
	head->b->next->data = tmp;
	put_instruction(SB);
	return (1);
}
