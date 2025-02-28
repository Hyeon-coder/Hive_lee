/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:42:38 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 15:01:41 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ps_lstnew(ft_atoi(args[i]));
		ps_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2 && args != argv)
	{
		ft_split_free(args);
		args = NULL;
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	args = NULL;
	init_stack(&stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_all_memory(&stack_a, &stack_b, args);
	return (0);
}
