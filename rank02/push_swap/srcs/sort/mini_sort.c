/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:46:41 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 01:39:29 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->num;
	mid = (*a)->next->num;
	bottom = (*a)->next->next->num;
	if (top > mid && mid < bottom && top < bottom)
		sa(a, 1);
	else if (top > mid && mid > bottom)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > bottom && mid < bottom)
		ra(a, 1);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(a, 1);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	while (size > 3)
		ps_push(a, b);
	sort_three(a);
	while (*b)
		ps_push(b, a);
}
