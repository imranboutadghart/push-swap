/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:08:30 by iboutadg          #+#    #+#             */
/*   Updated: 2024/04/24 18:08:50 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>


//macros
# define BUFFER_SIZE 4096
# define RA 1
# define RB 2
# define RRA 3
# define RRB 4
# define PA 5
# define PB 6
# define SA 7
# define SB 8
# define RR 9
# define RRR 10
# define SS 11

//structs
typedef struct s_stack {
	void			*data;
	struct s_stack	*next;
	int				cost;
}	t_stack;

typedef struct s_head {
	struct s_stack	*a;
	struct s_stack	*b;
	int				size_a;
	int				size_b;
}	t_head;

typedef int (*t_instruction)(t_head *head, int print);

void print_stack(t_stack *s);
// stack_implementation
t_stack	*create_node(void	*data);
t_stack	*push(t_stack **stack, void	*data);
t_stack	*push_back(t_stack **stack, void	*data);
void	*pop(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_sorted_reverse(t_stack *stack);
void	free_stack(t_stack *s);

// malloc and free implementations
void	*my_malloc(size_t n);
void	my_free(void *ptr);
void	free_all(void);

// utils
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, const char *s2);
int		in_str(char c, char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		error(void);
int		ko(void);
int		my_exit(int exit_code);

//instructions
int		push_a(t_head *head, int print);
int		push_b(t_head *head, int print);
int		rotate_a(t_head *head, int print);
int		rotate_b(t_head *head, int print);
int		rotate_r(t_head *head, int print);
int		r_rotate_a(t_head *head, int print);
int		r_rotate_b(t_head *head, int print);
int		r_rotate_r(t_head *head, int print);
int		swap_a(t_head *head, int print);
int		swap_b(t_head *head, int print);
int		swap_s(t_head *head, int print);

//instruction handlers
int		put_instruction(int instruction);

//parsing
t_stack	*parse(int ac, char **av);

//sorting functions
void	apply_indexes(t_head *head);
int		sort_3(t_head *head);
int		sort_5(t_head *head);
int		push_max(t_head *head);

#endif
