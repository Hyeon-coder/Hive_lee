/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:12:49 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/27 19:11:05 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*lst) > 1)
	{
		first = stack_pop(lst);
		second = stack_pop(lst);
		stack_push(lst, first);
		stack_push(lst, second);
	}
}

void	sa(t_stack **lst, int flag)
{
	ps_swap(lst);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **lst, int flag)
{
	ps_swap(lst);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **lst, t_stack **lst2)
{
	sa(lst, 0);
	sb(lst2, 0);
	write(1, "ss\n", 3);
}
