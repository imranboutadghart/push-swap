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

int	rotate_r(t_head *head)
{
	rotate_a(head);
	rotate_b(head);
	put_instruction(RR);
	return (1);
}

int	r_rotate_r(t_head *head)
{
	r_rotate_a(head);
	r_rotate_b(head);
	put_instruction(RRR);
	return (1);
}

int	swap_s(t_head *head)
{
	swap_a(head);
	swap_b(head);
	put_instruction(SS);
	return (1);
}
