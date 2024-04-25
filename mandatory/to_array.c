#include "push_swap.h"

static long	*stack_to_table(t_head *head, int size) {
	t_stack *tmp;
	long	*tab;
	int		i;

	tab = malloc(size * sizeof(long));
	tmp = head->a;
	i = 0;
	while (tmp)
	{
		tab[i++] = (long)tmp->data;
		tmp = tmp->next;
	}
	return (tab);
}

static void	sort_tab(long *tab, int size)
{
	long	i;
	long	j;
	long	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static long	find_data(long *tab, long data, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (tab[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

void apply_indexes(t_head *head)
{
	long	*tab;
	int		size;
	int		i;
	t_stack	*tmp;

	i = 0;
	size = head->size_a;
	tab = stack_to_table(head, size);
	tmp = head->a;
	sort_tab(tab, size);
	while (tmp)
	{
		tmp->data = (void *)find_data(tab, (long)tmp->data, size);
		tmp = tmp->next;
	}
	my_free(tab);
}
