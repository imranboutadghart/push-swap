#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int in_array(int *arr, int size, int n)
{
	int i = 0;

	while (i < size)
	{
		if (n == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	int size = atoi(av[1]);
	int	i = 0;
	int tmp;
	int *arr = new int[size];
	if (ac > 2)
		srand(atoi(av[2]));
	int modulo = (size * (size < 20)) + (100000 * (size >= 20));
	while(i < size)
	{
		while (in_array(arr, i, tmp = rand() % modulo - modulo / 2))
			;
		arr[i++] = tmp;
	}
	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
	delete[] arr;
}