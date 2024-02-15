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

static void	fix_position(t_head *head, t_stack *lc)
{
	int	position;
	int a_size;
	t_stack	*tmp;

	if (head->a == lc)
		return ;
	a_size = stack_size(head->a);
	position = 0;
	tmp = head->a;
	while (tmp->next && tmp->next != lc && ++position)
		tmp = tmp->next;
	while ((position <= a_size / 2) && position > 0 && rotate_a(head, 1))
		--position;
	while ((position > a_size / 2) && position < a_size && r_rotate_a(head, 1))
		++position;
}

int push_least_cost(t_head *head, t_stack *lc)
{
	int		position;

	fix_position(head, lc);
	return (1);
}
