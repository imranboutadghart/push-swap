/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:13 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/06 16:47:04by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fix_b(t_head *head)
{
	t_stack *tmp;
	int		i;
	int		reverse;

	tmp = head->b;
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
	fix_b(head);
	while (head->b)
		push_a(head, 1);
	return (1);
}

