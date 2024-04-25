/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:52:51 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/25 23:24:36 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_position(t_stack *stack)
{
	long	max;
	int		max_position;
	int		position;

	if (!stack)
		return (0);
	max = (long)stack->data;
	max_position = 0;
	position = 0;
	if (stack_sorted_reverse(stack))
		return (0);
	while (stack)
	{
		if ((long)stack->data > max)
		{
			max = (long)stack->data;
			max_position = position;
		}
		stack = stack->next;
		++position;
	}
	return (max_position);
}

int	push_max(t_head *head)
{
	int	size;
	int	max_pos;

	size = head->size_b;
	max_pos = get_max_position(head->b);
	while (max_pos > 0 && max_pos < size)
	{
		((max_pos <= size / 2) && rotate_b(head, 1)) || \
		((max_pos > size / 2) && r_rotate_b(head, 1));
		max_pos += (max_pos <= size / 2) * (-1) + (max_pos > size / 2);
	}
	push_a(head, 1);
	return (1);
}
