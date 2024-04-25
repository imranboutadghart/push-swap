/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:13:10 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/04 02:48:20 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**get_memory(void)
{
	static t_stack	*memory = NULL;

	return (&memory);
}

t_stack	*mem_create_node(void *data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	push_to_stack(t_stack **stack, void *data)
{
	t_stack	*new_node;

	new_node = mem_create_node(data);
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

void	*my_malloc(size_t size)
{
	void	*ptr;
	t_stack	**my_memory;

	ptr = malloc(size);
	my_memory = get_memory();
	push_to_stack(my_memory, ptr);
	return (ptr);
}
