/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:59:25 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 16:00:10 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (tmp)
	{
		position_b = calculate_position_in_b(head->b, (long)tmp->data);
		tmp->cost = calculate_cost(head, position_a, position_b);
		if (tmp->cost < least_costing->cost)
			least_costing = tmp;
		position_a++;
		tmp = tmp->next;
	}
	return (least_costing);
}
