/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:03:51 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/20 16:33:31 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3_case1(t_stack **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

static void	sort_3_case2(t_stack **stack_a, t_stack *head, int min)
{
	if (head->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_3_case3(t_stack **stack_a, t_stack *head, int min)
{
	if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
		sort_3_case1(stack_a);
	else if (head->index == next_min)
		sort_3_case2(stack_a, head, min);
	else
		sort_3_case3(stack_a, head, min);
}
