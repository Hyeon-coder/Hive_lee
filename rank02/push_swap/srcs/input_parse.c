/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 04:06:33 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 04:49:03 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	current = a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->num == compare->num)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

t_stack	*input_tmp_stack(char **args, int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_stack_lstnew(ft_atoi(args[i]));
		if (!new_node)
		{
			ft_stack_lstclear(&stack);
			return (NULL);
		}
		stack_append(&stack, new_node);
		i++;
	}
	return (stack);
}

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

t_stack	*input_parse(int ac, char **av)
{
	t_stack	*stack;
	char	**args;
	int		size;

	args = NULL;
	if (ac == 2 && av[1])
		args = ft_split(av[1], ' ');
	else if (ac > 2)
		args = av + 1;
	if (!args)
		return (NULL);
	if (ac == 2)
		size = count_args(args);
	else
		size = ac - 1;
	stack = input_tmp_stack(args, size);
	if (!stack && ac == 2)
		free_args(args);
	return (stack);
}
