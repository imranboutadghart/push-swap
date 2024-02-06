/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/06 17:28:38 by iboutadg         ###   ########.fr       */
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

void	print_stack(t_stack *stack)//////////////////////////////////////////////////////////
{
	while (stack)
	{
		printf("%ld->", (long)stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int	stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}