/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:44:23 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 05:03:17 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_numbers(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

int	main(int ac, char **av)
{
	char	**numbers;
	t_stack	*a;
	t_stack	*b;

	numbers = NULL;
	a = NULL;
	b = NULL;
	if (ac == 2 && av[1])
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			exit_error(1, NULL, NULL);
		a = input_parse(cnt_deli(av[1], ' '), numbers);
		free_numbers(numbers);
	}
	else if (ac > 2)
		a = input_parse(ac - 1, av);
	if (!a)
		exit_error(1, NULL, NULL);
	sort_branch(a, b, ft_stack_lstsize(a));
	free_stack(&a);
	free_stack(&b);
	return (0);
}
