/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:16 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/25 22:21:53 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_stack(t_stack *stack, void *data)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_atoi(const char *str, int index, t_stack	**stack)
{
	size_t	i;
	long	res;
	int		s;

	i = index;
	s = 1;
	res = 0;
	while (in_str(str[i], " \t\n\v\f\r"))
		i++;
	if (!str[i])
		return (i);
	if (('+' == str[i] || '-' == str[i]) && ('-' == str[i++]))
			s = -1;
	if (!str[i] || in_str(str[i], " \t\n\v\f\r"))
		return (free_stack(*stack), my_exit(error()));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((res > 2147483647 && s == 1) || (res > 2147483648 && s == -1))
			return (free_stack(*stack), my_exit(error()));
	}
	if ((!in_str(str[i], " \t\n\v\f\r") && str[i]) \
				|| in_stack(*stack, (void *)(res * s)))
		return (free_stack(*stack), my_exit(error()));
	return (push_back(stack, (void *)(res * s)), i);
}

static char	*get_one_big_str(int ac, char **av)
{
	int		i;
	char	*res;

	res = NULL;
	i = 1;
	while (i < ac)
	{
		res = ft_strjoin(res, av[i++]);
		if (!res)
			return (0);
	}
	return (res);
}

t_stack	*parse(int ac, char **av)
{
	int		i;
	char	*str;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	str = get_one_big_str(ac, av);
	if (!str)
		return (NULL);
	while (str[i])
		i = ft_atoi(str, i, &stack);
	my_free(str);
	return (stack);
}
