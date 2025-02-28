/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_branch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:46:44 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 01:39:25 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_branch(t_stack *a, t_stack *b, int size)
{
	if (size <= 3)
	{
		sort_three(&a);
	}
	else if (size <= 5)
	{
		sort_five(&a, &b, size);
	}
	else
	{
		radix_sort(&a, &b, size);
	}
}
