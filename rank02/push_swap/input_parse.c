/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:52:31 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/07 15:00:57 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*input_tmp_stack(int ac, char **av, int flag)
{
	t_stack	*rst;
	int		num;
	int		i;

	rst = NULL;
	if (flag == 1)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if ((i == 1 || i == 0) && !rst)
			rst = ft_lstnew(num);
		else
			stack_append(&rst, ft_lstnew(num));
		i++;
	}
	return (rst);
}

t_stack	*input_parse(int ac, char **av, int flag)
{
	t_stack	*rst;

	rst = NULL;
	if (flag == 1)
	{
		if (ac == 0)
			exit(0);
		if (ft_isvalid_input(av, flag))
			exit_error(1, NULL, NULL);
		rst = input_tmp_stack(ac, av, flag);
		if (check_double(rst))
			exit_error(1, rst, NULL);
	}
	else
	{
		if (ac == 1)
			exit(0);
		if (ft_isvalid_input(av, flag))
			exit_error(1, NULL, NULL);
		rst = input_tmp_stack(ac, av, flag);
		if (check_double(rst))
			exit_error(1, rst, NULL);
	}
	return (rst);
}
