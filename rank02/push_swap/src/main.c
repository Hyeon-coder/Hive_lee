/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:10:35 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/20 16:47:16 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char **arg, char *msg)
{
	ft_putendl_fd(msg, 1);
	if (arg)
	{
		ft_free(arg);
		free(arg);
	}
	exit(0);
}

static void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	char	*arg;
	int		i;

	i = -1;
	arg = argv[1];
	if (argc == 2)
		args = ft_split(arg, ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[++i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
	}
	index_stack(stack);
	if (argc == 2)
	{
		ft_free(args);
		free(args);
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
