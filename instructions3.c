/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:47:19 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/07 23:05:25 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_r(t_head *head, int print)
{
	(void)print;
	rotate_a(head, 0);
	rotate_b(head, 0);
	write(1, "rr\n", 3);
	return (1);
}

int	r_rotate_r(t_head *head, int print)
{
	(void)print;
	r_rotate_a(head, 0);
	r_rotate_b(head, 0);
	write(1, "rrr\n", 4);
	return (1);
}

int	swap_s(t_head *head, int print)
{
	(void)print;
	swap_a(head, 0);
	swap_b(head, 0);
	write(1, "ss\n", 3);
	return (1);
}
