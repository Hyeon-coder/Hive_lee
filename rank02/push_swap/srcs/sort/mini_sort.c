/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:52:12 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 15:39:04 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Sorts three elements in the stack. (스택 내 3개의 요소 정렬)
*/
static void	exec_sort_3(t_stack **stack_a, int min, int next_min)
{
	t_stack	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min && head->next->index == min)
		sa(stack_a);
	else if (head->index == next_min)
		rra(stack_a);
	else if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

/*
	Implements sorting logic for three elements. (3개의 요소를 정렬하는 로직 구현)
*/
void	sort_3(t_stack **stack_a)
{
	int	min;
	int	next_min;

	if (is_sorted(*stack_a))
		return ;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	exec_sort_3(stack_a, min, next_min);
}

/*
	Implements sorting logic for four elements. (4개의 요소를 정렬하는 로직 구현)
*/
void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(*stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

/*
	Implements sorting logic for five elements. (5개의 요소를 정렬하는 로직 구현)
*/
void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
