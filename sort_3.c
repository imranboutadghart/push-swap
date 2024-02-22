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

enum	e_myenum{R, S, REVR, RS, SR};

static int stack_state(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = s->data > s->next->data;
	b = s->data > s->next->next->data;
	c = s->next->data > s->next->next->data;
	if (!a && !b && c)
		return (SR);
	if (a && !b && !c)
		return (S);
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
	if ((stack_size(head->a) == 1) || (stack_size(head->a) == 2 && swap_a(head)))
		return (1);
	if (stack_sorted(tmp))
		return (1);
	state = stack_state(tmp);
	if ((state == R || state == RS) && rotate_a(head) && sort_3(head))
		return (1);
	if ((state == S  || state == SR) && swap_a(head) && sort_3(head))
		return (1);
	if (state == REVR && r_rotate_a(head))
		return (1);
	return (1);
}

