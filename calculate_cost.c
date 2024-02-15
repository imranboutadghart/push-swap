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

static int	calculate_position(t_head *head, void *data)
{
	t_stack *tmp;
	int		position;

	tmp = head->b;
	position = 0;
	if (!tmp || (data >= tmp->data && stack_sorted_reverse(head->b))\
			|| is_max_or_min(data, tmp))
		return (get_max_position(tmp) - 1);
	while (tmp && data < tmp->data && ++position)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (position);
}

static int	calculate_cost(t_head *head, int p_a, int p_b)
{
	int			res;
	static int	s_a = -1;
	static int	s_b = -1;

	if (s_a == -1 || s_b == -1)
	{
		s_a = stack_size(head->a);
		s_b = stack_size(head->b);
	}
	res = 1;
	res += p_a * (p_a <= s_a / 2) + (s_a - p_a) * (p_a > s_a / 2);
	res += p_b * (p_b <= s_b / 2) + (s_b - p_b) * (p_b > s_b / 2);
	return (res);
}

t_stack	*set_cost(t_head *head)
{
	t_stack	*tmp;
	t_stack	*least_costing;
	int		position_a;
	int		position_b;

	tmp = head->a;
	position_a = 0;
	least_costing = tmp;
	while(tmp) {
		position_b = calculate_position(head, tmp->data);
		tmp->cost = calculate_cost(head, position_a, position_b);
		if (tmp->cost < least_costing->cost)
			least_costing = tmp;
		position_a++;
		tmp = tmp->next;
	}
	return (least_costing);
}
