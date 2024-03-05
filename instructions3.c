/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/03/05 11:49:05 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_r(t_head *head, int print)
{
	rotate_a(head, 0);
	rotate_b(head, 0);
	if (print)
		put_instruction(RR);
	return (1);
}

int	r_rotate_r(t_head *head, int print)
{
	r_rotate_a(head, 0);
	r_rotate_b(head, 0);
	if (print)
		put_instruction(RRR);
	return (1);
}

int	swap_s(t_head *head, int print)
{
	swap_a(head, 0);
	swap_b(head, 0);
	if (print)
		if (print)
		if (print)
		put_instruction(SS);
	return (1);
}
