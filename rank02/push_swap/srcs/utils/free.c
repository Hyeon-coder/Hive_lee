/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:45:25 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/05 15:22:05 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Frees the memory allocated for a stack. (스택을 위한 할당된 메모리 해제)
*/
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

/*
	Frees allocated memory. (할당된 메모리 해제)
*/
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

/*
	Frees all dynamically allocated memory. (할당된 모든 메모리 해제)
*/
void	free_all_memory(t_stack **stack_a, t_stack **stack_b, char **args)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	if (args)
		ft_split_free(args);
}

/*
	Frees the memory allocated by ft_split. (ft_split이 할당한 메모리 해제)
*/
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
