/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:36:15 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/25 22:21:28 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = ft_strlen(str);
	dst = my_malloc((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	while (++i <= size)
		dst[i] = str[i];
	return (dst);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dst;

	if (!s1)
		return (ft_strjoin(ft_strdup(s2), ""));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dst = (char *)my_malloc((i + j + 2) * sizeof(char));
	if (!dst)
		return (0);
	k = -1;
	while (++k < i)
		dst[k] = s1[k];
	k--;
	while (++k < i + j)
		dst[k] = s2[k - i];
	dst[k++] = ' ';
	dst[k] = '\0';
	my_free(s1);
	return (dst);
}

int	in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
