/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:48:16 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:49:33 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write (1, s, i);
}

void	print_instructions(int *arr, int size)
{
	static char	strs[][5] = {"", "ra\n", "rb\n", "rra\n", "rrb\n", \
								"pa\n", "pb\n", "sa\n", "sb\n", \
								"rr\n", "rrr\n", "ss\n"};
	int			i;

	i = 0;
	while (i < size)
		put_str(strs[arr[i++]]);
}

int	put_instruction(int instruction)
{
	static int	arr[BUFFER_SIZE] = {0};
	static int	i = 0;

	arr[i++] = instruction;
	if (!instruction || BUFFER_SIZE - 1 == i)
	{
		print_instructions(arr, i);
		i = 0;
	}
	return (1);
}
