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

void	push_into_b(t_head *head)
{
	t_stack	*tmp;

	if (!head->b)
	{
		push_b(head);
		return ;
	}
	if (head->a->data > head->b->data)
	{
		push_b(head);
		return ;
	}
}

int sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

void	sort(t_head *head)
{
	if (!head->b && sorted(head->a))
		return ;
	
	push_into_b(head);
}

int	main(int ac, char **av)
{
	t_head	head;

	head.b = NULL;
	head.a = NULL;
	if (ac > 1)
	{
		head.a = parse(ac, av);
		print_stack(head.a);
		r_rotate_a(&head);// error here
		print_stack(head.a);
	}
	my_free(head.b);
	return (0);
}
