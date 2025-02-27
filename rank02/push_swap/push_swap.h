/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:37:42 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/20 21:48:24 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* 라딕스 정렬 함수 */
void	radix_sort(t_stack **a, t_stack **b);

/* 나머지 기존 선언 유지 */
t_stack	*input_parse(int ac, char **av, int flag);
int		ft_isvalid_input(char **av, int flag);
int		check_double(t_stack *a);
void	exit_error(int i, t_stack *a, t_stack *b);
int		ft_atoi(const char *str);
void	stack_push(t_stack **lst, t_stack *new);
t_stack	*stack_pop(t_stack **lst);
int		stack_peek(t_stack *lst);
void	free_stack(t_stack *stack);
t_stack	*ft_lstnew(int num);
t_stack	*input_tmp_stack(int ac, char **av, int flag);
int		ft_lstsize(t_stack *lst);
void	ps_push(t_stack **lst, t_stack **dst);
void	pa(t_stack **lst, t_stack **dst);
void	pb(t_stack **lst, t_stack **dst);
void	ps_swap(t_stack **lst);
void	sa(t_stack **lst, int flag);
void	sb(t_stack **lst, int flag);
void	ss(t_stack **lst, t_stack **lst2);
void	ps_rotate(t_stack **lst);
void	ra(t_stack **lst, int flag);
void	rb(t_stack **lst, int flag);
void	rr(t_stack **lst, t_stack **lst2);
void	ps_reverse(t_stack **lst);
void	rra(t_stack **lst, int flag);
void	rrb(t_stack **lst, int flag);
void	rrr(t_stack **lst, t_stack **lst2);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	stack_append(t_stack **stack, t_stack *new_node);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
size_t	ft_countword(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		is_sorted(t_stack *stack);

#endif
