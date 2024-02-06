/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:16 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/05 23:07:42 by iboutadg         ###   ########.fr       */
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
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i])
		return (i);
	if ('+' == str[i] || '-' == str[i])
		if ('-' == str[i++])
			s = -1;
	if (!str[i])
		exit(error());
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((res > 2147483647 && s == 1) || (res > 2147483648 && s == -1))
			my_exit(error());
	}
	if (!in_str(str[i], " \t\n\v\f\r") && str[i])
		my_exit(error());
	return (push(stack, (void *)(res * s)), i);
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
		res = ft_strjoin(res, " ");
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
	{
		i = ft_atoi(str, i, &stack);
		if (in_stack(stack->next, stack->data))
			my_exit(error());
	}
	my_free(str);
	return (stack);
}

