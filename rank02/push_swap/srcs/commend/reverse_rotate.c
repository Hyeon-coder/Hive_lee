/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:10:03 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 08:29:31 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ps_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ps_lstsize(*stack_a) < 2) || (ps_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
