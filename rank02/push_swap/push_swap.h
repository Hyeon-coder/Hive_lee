/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/13 20:47:36 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Stack
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

// free
void	free_stack(t_stack **stack);
void	ft_free(char **str);
void	free_all_memory(t_stack **stack_a, t_stack **stack_b, char **args);
void	ft_split_free(char **args);

// utils
int		is_sorted(t_stack *stack);
int		get_distance(t_stack **stack, int index);
void	make_top(t_stack **stack, int distance);
void	index_stack(t_stack **stack);
void	ft_check_args(int argc, char **argv);
void	ft_error(char *msg, char **tgt_arr);

// stack_utils
void	print_list(t_stack *head);
t_stack	*ps_lstnew(int value);
void	ps_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ps_lstlast(t_stack *head);
void	ps_lstadd_back(t_stack **stack, t_stack *new);
int		ps_lstsize(t_stack *head);

// sort
int		get_min(t_stack **stack, int val);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
int		get_max_bits(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// commend functions
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);

int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

#endif
