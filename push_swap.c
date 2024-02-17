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
	t_stack *least_costing;

	if (!head->b && stack_sorted(head->a))
		return ;
	if (stack_size(head->a) <= 3 && sort_3(head))
		return ;
	if (!head->b && push_b(head, 1))
		push_b(head, 1);
	if (!head->a && push_all_to_a(head))
		return ;
	least_costing = set_cost(head);
	push_least_cost(head, least_costing);
	sort(head);
}

int	main(int ac, char **av)
{
	t_head	head;

	head.b = NULL;
	head.a = NULL;
	push(&head.b, (void *)6);//1 3 7 9 5
	push(&head.b, (void *)8);
	push(&head.b, (void *)2);
	push(&head.b, (void *)4);
	if (ac > 1)
	{
		printf ("b:   ");
		print_stack(head.b);
		head.a = parse(ac, av);
		printf ("a:   ");
		print_stack(head.a);
		t_stack *tmp = set_cost(&head);//set cost errors
		printf ("cost:");
		print_stack_cost(head.a);
		//push_least_cost(&head, tmp);
		printf ("a_n:  ");
		//print_stack(head.a);
		printf("least costing(%ld)\n", (long)tmp->data);
	}
	free_stack(head.a);
	free_stack(head.b);
	my_free(head.b);
	return (0);
}
