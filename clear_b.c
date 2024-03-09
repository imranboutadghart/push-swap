/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:52:51 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:52:57 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fix_a(t_head *head)
{
	t_stack	*tmp;
	int		i;
	int		reverse;

	tmp = head->a;
	if (!tmp)
		return (0);
	i = 1;
	reverse = 0;
	while (tmp->next && tmp->data < tmp->next->data && i++)
		tmp = tmp->next;
	if (!tmp->next)
		i = 0;
	if (i > stack_size(head->a) / 2)
	{
		reverse = 1;
		i = stack_size(head->a) - i;
	}
	while (!reverse && i--)
		rotate_a(head, 1);
	while (reverse && i--)
		r_rotate_a(head, 1);
	return (1);
}

static int	fix_b(t_head *head)
{
	t_stack	*tmp;
	int		i;
	int		reverse;

	tmp = head->b;
	if (!tmp)
		return (0);
	i = 1;
	reverse = 0;
	while (tmp->next && tmp->data > tmp->next->data && i++)
		tmp = tmp->next;
	if (!tmp->next)
		i = 0;
	if (i > stack_size(head->b) / 2)
	{
		reverse = 1;
		i = stack_size(head->b) - i;
	}
	while (!reverse && i--)
		rotate_b(head, 1);
	while (reverse && i--)
		r_rotate_b(head, 1);
	return (1);
}

int	push_all_to_a(t_head *head)
{
	int	position;
	int	size_a;

	if (head->b)
		fix_b(head);
	while (head->b)
	{
		position = calculate_position_in_a(head->a, head->b->data);
		size_a = stack_size(head->a);
		if (size_a - 1 == position)
			r_rotate_a(head, 1);
		else if (1 == position)
			rotate_a(head, 1);
		else if (size_a - 2 == position && r_rotate_a(head, 1))
			r_rotate_a(head, 1);
		else if (size_a > 3 && size_a - 3 == position \
				&& r_rotate_a(head, 1) && r_rotate_a(head, 1))
			r_rotate_a(head, 1);
		push_a(head, 1);
	}
	fix_a(head);
	return (1);
}
