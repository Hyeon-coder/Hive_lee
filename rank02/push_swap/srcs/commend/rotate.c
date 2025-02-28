/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:38:08 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 15:43:36 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/*
	rotate: Rotates a stack upwards. (스택을 위로 회전)
	ra: Rotates stack A upwards. (스택 A를 위로 회전)
	rb: Rotates stack B upwards. (스택 B를 위로 회전)
	rr: Rotates both stacks upwards. (두 스택을 동시에 위로 회전)
*/
int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ps_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ps_lstsize(*stack_a) < 2) || (ps_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
