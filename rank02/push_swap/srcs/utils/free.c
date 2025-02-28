/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:45:25 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 13:54:06 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (stack && *stack)
	{
		current = *stack;
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*stack = NULL;
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_all_memory(t_stack **stack_a, t_stack **stack_b, char **args)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	if (args)
		ft_split_free(args);
	write(1, "here", 4);
}

void	ft_split_free(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
