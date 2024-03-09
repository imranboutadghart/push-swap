/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:13 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/09 15:48:03 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ROT 1
#define RROT 2

static void	print_instructions(char **arr, int size1, int size2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size1 && j < size2 && ROT == arr[0][i] \
			&& ROT == arr[1][j] && ++i && ++j)
		put_instruction(RR);
	while (i < size1 && j < size2 && RROT == arr[0][i] \
			&& RROT == arr[1][j] && ++i && ++j)
		put_instruction(RRR);
	while (i < size1 \
			&& ((ROT == arr[0][i] && put_instruction(RA)) \
				|| (RROT == arr[0][i] && put_instruction(RRA))))
		++i;
	while (j < size2 \
			&& ((ROT == arr[1][j] && put_instruction(RB)) \
				|| (RROT == arr[1][j] && put_instruction(RRB))))
		++j;
}

static int	stack_instructions(int position, int instruction)
{
	static char	*arr[2];
	static int	indexes[2] = {0, 0};
	static int	size = 0;

	if (!instruction)
	{
		print_instructions(arr, indexes[0], indexes[1]);
		my_free(arr[0]);
		my_free(arr[1]);
		arr[0] = 0;
		arr[1] = 0;
		indexes[0] = 0;
		indexes[1] = 0;
		size = 0;
		return (1);
	}
	if (!size || indexes[0] == size || indexes[1] == size || !arr[0])
	{
		arr[0] = my_realloc(arr[0], size, size * 2 + !size * BUFFER_SIZE);
		arr[1] = my_realloc(arr[1], size, size * 2 + !size * BUFFER_SIZE);
		size = size * 2 + !size * BUFFER_SIZE;
	}
	arr[position][indexes[position]] = instruction;
	indexes[position]++;
	return (1);
}

static void	fix_position_a(t_head *head, t_stack *lc)
{
	int		position;
	int		a_size;
	t_stack	*tmp;

	if (head->a == lc)
		return ;
	a_size = stack_size(head->a);
	position = 0;
	tmp = head->a;
	while (tmp->next && tmp != lc && ++position)
		tmp = tmp->next;
	while ((position <= a_size / 2) && position > 0 && \
			rotate_a(head, 0) && stack_instructions(0, ROT))
		--position;
	while ((position > a_size / 2) && position < a_size \
			&& r_rotate_a(head, 0) && stack_instructions(0, RROT))
		++position;
}

static void	fix_position_b(t_head *head, t_stack *lc)
{
	int	position;
	int	b_size;

	b_size = stack_size(head->b);
	position = calculate_position_in_b(head->b, lc->data);
	while ((position <= b_size / 2) && position > 0 \
			&& rotate_b(head, 0) && stack_instructions(1, ROT))
		--position;
	while ((position > b_size / 2) && position < b_size \
			&& r_rotate_b(head, 0) && stack_instructions(1, RROT))
		++position;
}

int	push_least_cost(t_head *head, t_stack *lc)
{
	fix_position_a(head, lc);
	fix_position_b(head, lc);
	stack_instructions(0, 0);
	push_b(head, 1);
	return (1);
}
