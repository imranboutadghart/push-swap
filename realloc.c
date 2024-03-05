#include "push_swap.h"

void	*my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new;
	unsigned char	*tmp;
	size_t			i;

	if (new_size < old_size)
		return (ptr);
	new = my_malloc(new_size);
	if (!new)
		my_exit (1);
	tmp = ptr;
	i = 0;
	while (i < old_size)
		new[i] = tmp[i];
	my_free(ptr);
	return ((void *)new);
}
