/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:54:58 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/25 23:22:42 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define R 0
#define SW 1
#define REVR 2
#define RS 3
#define SR 4

static int	stack_state(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = (long)s->data > (long)s->next->data;
	b = (long)s->data > (long)s->next->next->data;
	c = (long)s->next->data > (long)s->next->next->data;
	if (!a && !b && c)
		return (SR);
	if (a && !b && !c)
		return (SW);
	if (!a && b && c)
		return (REVR);
	if (a && b && !c)
		return (R);
	if (a && b && c)
		return (RS);
	return (-1);
}

int	sort_3(t_head *head)
{
	t_stack	*tmp;
	int		state;

	tmp = head->a;
	if (((head->size_a) == 1) \
			|| ((head->size_a) == 2 && swap_a(head, 1)))
		return (1);
	if (stack_sorted(tmp))
		return (1);
	state = stack_state(tmp);
	if ((state == R || state == RS) && rotate_a(head, 1) && sort_3(head))
		return (1);
	if ((state == SW || state == SR) && swap_a(head, 1) && sort_3(head))
		return (1);
	if (state == REVR && r_rotate_a(head, 1))
		return (1);
	return (1);
}

static int	get_min_position(t_stack *stack, int has_zero)
{
	t_stack	*tmp;
	int		position;

	tmp = stack;
	position = 0;
	if (has_zero)
	{
		while (tmp && tmp->data != 0 && ++position)
			tmp = tmp->next;
		return (position);
	}
	while (tmp && tmp->data != (void *)(uintptr_t)1 && ++position)
		tmp = tmp->next;
	return (position);
}

static void	operation(t_head *head, int pos, int size)
{
	while (pos > 0 && pos < size)
	{
		((pos <= size / 2) && rotate_a(head, 1)) || \
		((pos > size / 2) && r_rotate_a(head, 1));
		pos += (pos <= size / 2) * (-1) + (pos > size / 2);
	}
}

int	sort_5(t_head *head)
{
	int	size;
	int	pos;
	int	flag;

	pos = get_min_position(head->a, 1);
	size = (head->size_a);
	operation(head, pos, size);
	push_b(head, 1);
	if (--size == 3 && sort_3(head) && push_a(head, 1))
		return (1);
	pos = get_min_position(head->a, 0);
	operation(head, pos, size);
	flag = !stack_sorted(head->a);
	if (flag)
		push_b(head, 1);
	sort_3(head);
	if (flag)
		push_a(head, 1);
	push_a(head, 1);
	return (1);
}
