/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:54:58 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:58:08 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

enum	e_myenum{r, sw, revr, rs, sr};

static int	stack_state(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = s->data > s->next->data;
	b = s->data > s->next->next->data;
	c = s->next->data > s->next->next->data;
	if (!a && !b && c)
		return (sr);
	if (a && !b && !c)
		return (sw);
	if (!a && b && c)
		return (revr);
	if (a && b && !c)
		return (r);
	if (a && b && c)
		return (rs);
	return (-1);
}

int	sort_3(t_head *head)
{
	t_stack	*tmp;
	int		state;

	tmp = head->a;
	if ((stack_size(head->a) == 1) \
			|| (stack_size(head->a) == 2 && swap_a(head, 1)))
		return (1);
	if (stack_sorted(tmp))
		return (1);
	state = stack_state(tmp);
	if ((state == r || state == rs) && rotate_a(head, 1) && sort_3(head))
		return (1);
	if ((state == sw || state == sr) && swap_a(head, 1) && sort_3(head))
		return (1);
	if (state == revr && r_rotate_a(head, 1))
		return (1);
	return (1);
}
