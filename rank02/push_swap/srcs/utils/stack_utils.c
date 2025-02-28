/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:43:55 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 15:56:32 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Creates a new node for the push_swap stack. (push_swap 스택의 새로운 노드 생성)
*/
t_stack	*ps_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

/*
	Adds an element to the front of the push_swap list.
	(push_swap 리스트 앞에 요소 추가)
*/
void	ps_lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

/*
	Returns the last node of the push_swap stack. (push_swap 스택의 마지막 노드를 반환)
*/
t_stack	*ps_lstlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

/*
	Adds an element to the back of the push_swap list.
	(push_swap 리스트 뒤에 요소 추가)
*/
void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ps_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/*
	Returns the size of the push_swap list. (push_swap 리스트 크기 반환)
*/
int	ps_lstsize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
