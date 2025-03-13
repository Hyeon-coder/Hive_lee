/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:42:45 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/14 00:56:45 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Checks if the stack is sorted. (스택이 정렬되었는지 확인)
*/
int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
	Calculates the distance of an element from the top.
	(요소가 스택의 맨 위에서 얼마나 떨어져 있는지 계산)
*/
int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

/*
	Moves a specific element to the top of the stack.
	(특정 요소를 스택 맨 위로 이동)
*/
void	make_top(t_stack **stack, int distance)
{
	t_stack	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ps_lstsize(head) - distance;
	if (distance <= (ps_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}

/*
	Prints the stack list. (스택 리스트를 출력)
*/
void	print_list(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

/*
	에러 메시지 출력 후 프로그램 종료
*/
void	ft_error(char **args)
{
	if (args)
		ft_free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}
