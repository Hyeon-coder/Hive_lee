/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:14:38 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/28 01:41:56 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ps_rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (ft_stack_lstsize(*lst) > 1)
	{
		tmp = stack_pop(lst);
		stack_append(lst, tmp);
	}
}

void	ra(t_stack **lst, int flag)
{
	ps_rotate(lst);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **lst, int flag)
{
	ps_rotate(lst);
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **lst, t_stack **lst2)
{
	ra(lst, 0);
	rb(lst2, 0);
	write(1, "rr\n", 3);
}
