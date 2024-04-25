/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:23:12 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/25 23:23:37 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_sort(t_head *head)
{
	int			range;
	static int	value;

	if (!value)
		value = 4 * ((head->size_a) < 350) + 10 * ((head->size_a) >= 350);
	range = ((head->size_a) / value);
	if (head->a->data < (void *)(uintptr_t)(head->size_b))
		push_b(head, 1);
	else if (head->a->data <= (void *)(uintptr_t)(head->size_b) + range)
	{
		push_b(head, 1);
		rotate_b(head, 1);
	}
	else
		rotate_a(head, 1);
}

void	push_swap(t_head *head)
{
	if (stack_sorted(head->a))
		return ;
	if ((head->size_a) <= 3 && sort_3(head))
		return ;
	if (!head->b && (head->size_a) <= 5 && sort_5(head))
		return ;
	while (head->a)
		the_sort(head);
	while (head->b)
		push_max(head);
}

int	main(int ac, char **av)
{
	t_head	head;

	head.b = NULL;
	if (ac > 1)
	{
		head.a = parse(ac, av);
		if (!head.a)
			my_exit(error());
		head.size_a = stack_size(head.a);
		head.size_b = 0;
		apply_indexes(&head);
		push_swap(&head);
	}
	free_stack(head.a);
	free_stack(head.b);
	put_instruction(0);
	return (0);
}
