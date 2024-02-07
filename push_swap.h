/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:30 by iboutadg          #+#    #+#             */
/*   Updated: 2024/02/07 17:00:09 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>/////////////////////////////////////////////////////////////////
#include <limits.h>

typedef struct s_stack {
	void			*data;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_head {
	struct s_stack	*a;
	struct s_stack	*b;
}	t_head;

// stack_implementation
t_stack	*create_node(void	*data);
t_stack	*push(t_stack **stack, void	*data);
void	*pop(t_stack **stack);
void	print_stack(t_stack *stack);
int		stack_size(t_stack *stack);

// malloc and free implementations
void	*my_malloc(size_t n);
void	my_free(void *ptr);
void	free_all(void);

// utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, const char *s2);
int		in_str(char c, char *str);
int		error(void);
void	my_exit(int exit_code);

//instructions
int	push_a(t_head *head);
int	push_b(t_head *head);
int	rotate_a(t_head *head);
int	rotate_b(t_head *head);
int	rotate_r(t_head *head);
int r_rotate_a(t_head *head);
int r_rotate_b(t_head *head);
int r_rotate_r(t_head *head);
int	swap_a(t_head *head);
int	swap_b(t_head *head);

//parsing
t_stack	*parse(int ac, char **av);


#endif