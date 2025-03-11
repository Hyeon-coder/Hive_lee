/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:38:49 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/11 15:24:23 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	swap: Swaps the top two elements of a stack. (스택의 맨 위 두 요소 교환)
	sa: Swaps the top two elements of stack A. (스택 A의 맨 위 두 요소 교환)
	sb: Swaps the top two elements of stack B. (스택 B의 맨 위 두 요소 교환)
	ss: Swaps the top two elements of both stacks. (두 스택의 맨 위 두 요소 교환)
*/
int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((ps_lstsize(*stack_a) < 2) || (ps_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
