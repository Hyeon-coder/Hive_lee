/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:03:01 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 03:44:53 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	stack_append(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!stack || !new_node)
		return ;
	if (!(*stack))
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

t_stack	*stack_pop(t_stack **lst)
{
	t_stack	*popped_node;

	if (!lst || !*lst)
		return (NULL);
	popped_node = *lst;
	*lst = (*lst)->next;
	popped_node->next = NULL;
	return (popped_node);
}

int	stack_peek(t_stack *lst)
{
	if (!lst)
		return (0);
	return (lst->num);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}
