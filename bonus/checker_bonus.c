/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:09:58 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/26 17:07:36 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instruction(t_head *head, int instruction)
{
	static t_instruction	jump_table[11] = {rotate_a, rotate_b, r_rotate_a,
		r_rotate_b, push_a, push_b,
		swap_a, swap_b, rotate_r,
		r_rotate_r, swap_s};

	jump_table[instruction - 1](head, 0);
}

int	get_instruction(t_head *head, char *s)
{
	int	ins;

	ins = (!ft_strncmp(s, "ra\n", 7)) * RA + (!ft_strncmp(s, "rrb\n", 7)) * RRB
		+ (!ft_strncmp(s, "rra\n", 7)) * RRA + (!ft_strncmp(s, "rb\n", 7)) * RB
		+ (!ft_strncmp(s, "pa\n", 7)) * PA + (!ft_strncmp(s, "pb\n", 7)) * PB
		+ (!ft_strncmp(s, "sa\n", 7)) * SA + (!ft_strncmp(s, "sb\n", 7)) * SB
		+ (!ft_strncmp(s, "rr\n", 7)) * RR + (!ft_strncmp(s, "rrr\n", 7)) * RRR
		+ (!ft_strncmp(s, "ss\n", 7)) * SS;
	if (!ins)
	{
		get_next_line(-1);
		free_stack(head->a);
		free_stack(head->b);
		my_exit(error());
	}
	return (ins);
}

int	main(int ac, char **av)
{
	static t_head	head = {NULL, NULL, 0, 0};
	char			*line;

	if (ac <= 1)
		return (0);
	head.a = parse(ac, av);
	if (!head.a)
		my_exit(error());
	head.size_a = stack_size(head.a);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		do_instruction(&head, get_instruction(&head, line));
		my_free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(head.a) && !head.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(head.a);
	free_stack(head.b);
	free_all();
	return (0);
}
