/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:13 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/06 16:47:04by iboutadg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fix_position_a(t_head *head, t_stack *lc)
{
	int	position;
	int a_size;
	t_stack	*tmp;

	if (head->a == lc)
		return ;
	a_size = stack_size(head->a);
	position = 0;
	tmp = head->a;
	while (tmp->next && tmp != lc && ++position)
		tmp = tmp->next;
	while ((position <= a_size / 2) && position > 0 && rotate_a(head))
		--position;
	while ((position > a_size / 2) && position < a_size && r_rotate_a(head))
		++position;
}

static void	fix_position_b(t_head *head, t_stack *lc)
{
	int	position;
	int b_size;
	
	b_size = stack_size(head->b);
	position = calculate_position_in_b(head->b, lc->data);
	while ((position <= b_size / 2) && position > 0 && rotate_b(head))
		--position;
	while ((position > b_size / 2) && position < b_size && r_rotate_b(head))
		++position;
}

int push_least_cost(t_head *head, t_stack *lc)
{
	fix_position_a(head, lc);
	fix_position_b(head, lc);
	push_b(head);
	return (1);
}
