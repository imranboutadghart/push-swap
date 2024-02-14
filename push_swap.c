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

void	sort(t_head *head)
{
	if (!head->b && stack_sorted(head->a))
		return ;
	if (stack_size(head->a) <= 3 && sort_3(head))
		return ;
	if (!head->b && push_b(head, 1))
		push_b(head, 1);
	if (!head->a && push_all_to_a(head))
		return ;
	set_cost(head);
	//push_least_cost(head);
	sort(head);
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
		set_cost(&head);
		print_stack_cost(head.a);
	}
	free_stack(head.a);
	free_stack(head.b);
	my_free(head.b);
	return (0);
}
