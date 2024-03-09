/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:51:27 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:51:30 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	stack_sorted_reverse(t_stack *stack)
{
	while (stack->next)
	{
		if ((long)stack->data <= (long)stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((long)stack->data > (long)stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		my_free(s);
		s = tmp;
	}
}
