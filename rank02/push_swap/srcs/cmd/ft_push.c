/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:14:47 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/28 01:38:50 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ps_push(t_stack **lst, t_stack **dst)
{
	t_stack	*tmp;

	if (ft_stack_lstsize(*lst) >= 1)
	{
		tmp = stack_pop(lst);
		stack_push(dst, tmp);
	}
}

void	pa(t_stack **lst, t_stack **dst)
{
	ps_push(lst, dst);
	write(1, "pa\n", 3);
}

void	pb(t_stack **lst, t_stack **dst)
{
	ps_push(lst, dst);
	write(1, "pb\n", 3);
}
