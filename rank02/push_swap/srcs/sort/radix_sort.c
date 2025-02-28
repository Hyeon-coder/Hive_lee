/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/28 01:39:28 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_stack	*temp;

	max = 0;
	bits = 0;
	temp = stack;
	while (temp)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static int	get_bit_count(int num)
{
	int	bits;

	bits = 0;
	while (num > 0)
	{
		num >>= 1;
		bits++;
	}
	return (bits);
}

static void	bit_grouping(t_stack **a, t_stack **b, int threshold, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_bit_count((*a)->num) > threshold)
			pb(a, b);
		else
			ra(a, 1);
		i++;
	}
}

static void	bit_pass(t_stack **a, t_stack **b, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*a)->num >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a, 1);
		j++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	max_bits;
	int	threshold;

	if (is_sorted(*a))
		return ;
	max_bits = get_max_bits(*a);
	threshold = 11;
	bit_grouping(a, b, threshold, size);
	i = 0;
	while (i < max_bits)
	{
		bit_pass(a, b, i, size);
		while (*b)
			pa(b, a);
		i++;
	}
}
