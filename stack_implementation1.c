/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/07 16:39:19 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(void *data)
{
	t_stack	*new_node;

	new_node = (t_stack *)my_malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*push(t_stack **stack, void *data)
{
	t_stack	*new_node;

	new_node = create_node(data);
	new_node->next = *stack;
	*stack = new_node;
	return (*stack);
}

t_stack	*push_back(t_stack **stack, void *data)
{
	t_stack	*new_node;
	t_stack *tmp;

	new_node = create_node(data);
	if (!*stack)
	{
		*stack = new_node;
		return (*stack);
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (*stack);
}

void	*pop(t_stack **stack)
{
	t_stack	*tmp;
	void	*data;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	data = tmp->data;
	my_free(tmp);
	return (data);
}

void	print_stack_cost(t_stack *stack)//////////////////////////////////////////////////////////
{
	printf("-->");
	while (stack)
	{
		if (0 > (long)stack->data)
			printf("(%ld)%s", (long)stack->cost, stack->next ? "->" : "");
		else
			printf("%ld%s", (long)stack->cost, stack->next ? "->" : "");
		stack = stack->next;
	}
	printf("|\n");
}

void	print_stack(t_stack *stack)//////////////////////////////////////////////////////////
{
	printf("-->");
	while (stack)
	{
		if (0 > (long)stack->data)
			printf("(%ld)%s", (long)stack->data, stack->next ? "->" : "");
		else
			printf("%ld%s", (long)stack->data, stack->next ? "->" : "");
		stack = stack->next;
	}
	printf("|\n");
}

