#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int error(void *arr)
{
	write(2, "Error\n", 6);
	if (arr)
		free(arr);
	return (1);
}

int	ft_atoi(const char *str, int *err)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	if ('+' == str[i] || '-' == str[i])
		if ('-' == str[i++])
			sign = -1;
	if (!str[i])
		*err = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
			*err = 1;
	}
	if (str[i])
		*err = 1;
	return ((int )(sign * result));
}

int *parse(int ac, char **av)
{
	int i;
	int j;
	int *arr;
	int err;

	arr = malloc((ac - 1) * sizeof(int));
	if (!arr)
		exit(error(0));
	i = 1;
	err = 0;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i], &err);
		j = 0;
		while (j < i - 1)
		{
			if (arr[i - 1] == arr[j++])
				exit(error(arr));
		}
		if (err)
			exit(error(arr));
		i++;
	}
	return (arr);
}

int main(int ac, char **argv)
{
	int *arr;
	int i;

	arr = NULL;
	if (ac > 1)
	{
		arr = parse(ac, argv);
		i = 0;
		while (i < ac - 1)
			printf("%d->", arr[i++]);
		printf("\n");
	}
	free(arr);
	return (0);
}
