/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:33:56 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/04 02:41:38 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**get_memory(void);

void	my_free(void *ptr)
{
	free(ptr);
}

void	free_all(void)
{
	return ;
}

void	*my_malloc(size_t size)
{
	return (malloc(size));
}
