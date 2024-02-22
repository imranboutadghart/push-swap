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

static int is_max_or_min(void *data, t_stack *stack)
{
	void	*min;
	void	*max;
	
	if (!stack)
		return (1);
	min = stack->data;
	max = stack->data;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	if (data >= max || data <= min)
		return (1);
	return (0);
}

static int	get_min_position(t_stack *stack)
{
	void	*min;
	int		min_position;
	int		position;

	min = stack->data;
	min_position = 1;
	position = 0;
	if (!stack || stack_sorted_reverse(stack))
		return (1);
	while (stack && ++position)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_position = position;
		}
		stack = stack->next;
	}
	return (min_position);
}

static int	get_max_position(t_stack *stack)
{
	void	*max;
	int		max_position;
	int		position;

	max = stack->data;
	max_position = 1;
	position = 0;
	if (!stack || stack_sorted_reverse(stack))
		return (1);
	while (stack && ++position)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_position = position;
		}
		stack = stack->next;
	}
	return (max_position);
}

int	calculate_position_in_b(t_stack *s, void *data)
{
	t_stack *tmp;
	int		position;
	int		max_position;

	tmp = s;
	if (!tmp)
		return (0);
	position = 0;
	max_position = get_max_position(tmp);
	if ((data >= tmp->data && stack_sorted_reverse(s))\
			|| is_max_or_min(data, tmp))
		return (max_position - 1);
	while (tmp && ++position != max_position)
		tmp = tmp->next;
	while (tmp && data < tmp->data)
	{
		if (!tmp->next)
		{
			tmp = s;
			position = 1;
			continue ;
		}
		tmp = tmp->next;
		++position;
	}
	return (position - 1);
}

int	calculate_position_in_a(t_stack *s, void *data)
{
	t_stack *tmp;

	tmp = s;
	if (!tmp)
		return (0);
	if (3 == stack_size(s) && is_max_or_min(data, tmp))
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data < data)
		return (0);
	tmp = s;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->data < data)
		return (stack_size(s) - 1);
	tmp = s;
	while (tmp && tmp->next && tmp->next->next && tmp->next->next->next)
		tmp = tmp->next;
	if (tmp->data < data)
		return (stack_size(s) - 2);
	if (is_max_or_min(data, s))
		return (get_min_position(s) - 1);
	return (0);
}
