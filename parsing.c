/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:16 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/04 01:23:27 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error()
{
	write(2, "Error\n", 6);
	return (1);
}

void	my_exit(int exit_code)
{
	free_all();
	exit(exit_code);
}

int	ft_atoi(const char *str, int index, t_stack	**stack)
{
	size_t	i;
	long	result;
	int		sign;

	i = index;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i])
		return (i);
	if ('+' == str[i] || '-' == str[i])
		if ('-' == str[i++])
			sign = -1;
	if (!str[i])
		exit(error());
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
			my_exit(error());
	}
	if (!in_str(str[i], " \t\n\v\f\r") && str[i])
		my_exit(error());
	return (push(stack, (void *)(result * sign)), i);
}

t_stack	*parse(char *str)
{
	int i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (str[i])
	{
		i = ft_atoi(str, i, &stack);
	}
	return (stack);
}

char	*get_one_big_str(int ac, char **av)
{
	int		i = 1;
	char	*res;

	res = NULL;
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

int main(int ac, char **av)
{
	t_stack	*stack_a;
	char *str;

	stack_a = NULL;
	if (ac > 1)
	{
		str = get_one_big_str(ac, av);
		if (!str)
			return (0);
		stack_a = parse(str);
		my_free(str);
		print_stack(stack_a);
	}
	my_free(stack_a);
	return (0);
}
