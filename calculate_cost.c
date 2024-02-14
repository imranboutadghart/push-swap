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

int	calculate_location(t_head *head, void *data)
{
	t_stack *tmp;
	int	location;

	tmp = head->b;
	location = 0;
	while (tmp && data < tmp->data && ++location)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (location);
}

int	calculate_cost(int l_a, int l_b, int s_a, int s_b)
{
	int	res;

	res = 1;
	res += l_a * (l_a <= s_a / 2) + (s_a - l_a) * (l_a > s_a / 2);
	res += l_b * (l_b <= s_b / 2) + (s_b - l_b) * (l_b > s_b / 2);
	return (res);
}

int	set_cost(t_head *head)
{
	t_stack	*tmp;
	int		location_a;
	int		location_b;
	int		size_a;
	int		size_b;

	tmp = head->a;
	size_a = stack_size(head->a);
	size_b = stack_size(head->b);
	location_a = 0;
	while(tmp)
	{
		location_b = calculate_location(head, tmp->data);
		tmp->cost = calculate_cost(location_a, location_b,\
				size_a, size_b);
		location_a++;
		tmp = tmp->next;
	}
	return (1);
}
