/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:33:56 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/04 02:34:37 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**get_memory(void);

void	my_free(void *ptr)
{
	t_stack	**my_memory;
	t_stack	*tmp1;
	t_stack	*tmp2;
	
	my_memory = get_memory();
	if (!ptr || !*my_memory)
		return ;
	tmp1 = *my_memory;
	tmp2 = tmp1;
	while (tmp1 && tmp2)
	{
		if (tmp2->data == ptr)
		{
			if (tmp1 == tmp2)
				*my_memory = tmp1->next;
			tmp1->next = tmp2->next;
			free(tmp2->data);
			free(tmp2);
			return ;
		}
		if (tmp1 != tmp2)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
}

void	free_all()
{
	t_stack	**my_memory;
	t_stack	*tmp1;
	t_stack	*tmp2;

	my_memory = get_memory();
	tmp1 = *my_memory;
	*my_memory = NULL;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
}
