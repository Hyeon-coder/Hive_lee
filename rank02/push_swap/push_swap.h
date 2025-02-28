/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:37:42 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 03:44:58 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* parsing */
int		ft_isvalid_input(char **av, int flag);
t_stack	*input_parse(int ac, char **av);
int		check_double(t_stack *a);
t_stack	*input_tmp_stack(char **args, int size);

/* commend */
void	ps_swap(t_stack **lst);
void	sa(t_stack **lst, int flag);
void	sb(t_stack **lst, int flag);
void	ss(t_stack **lst, t_stack **lst2);
void	ps_rotate(t_stack **lst);
void	ra(t_stack **lst, int flag);
void	rb(t_stack **lst, int flag);
void	rr(t_stack **lst, t_stack **lst2);
void	ps_reverse(t_stack **lst);
void	ps_push(t_stack **lst, t_stack **dst);
void	pa(t_stack **lst, t_stack **dst);
void	pb(t_stack **lst, t_stack **dst);
void	rra(t_stack **lst, int flag);
void	rrb(t_stack **lst, int flag);
void	rrr(t_stack **lst, t_stack **lst2);

/* sort */
void	sort_branch(t_stack *a, t_stack *b, int size);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int size);
void	radix_sort(t_stack **a, t_stack **b, int size);
int		is_sorted(t_stack *stack);

/* utils */
void	exit_error(int i, t_stack *a, t_stack *b);
void	free_stack(t_stack **stack);
t_stack	*ft_stack_lstnew(int content);
int		ft_stack_lstsize(t_stack *lst);
void	ft_stack_lstclear(t_stack **stack);

/* stack_utils */
void	stack_push(t_stack **lst, t_stack *new);
t_stack	*stack_pop(t_stack **lst);
int		stack_peek(t_stack *lst);
void	stack_append(t_stack **stack, t_stack *new_node);

#endif
