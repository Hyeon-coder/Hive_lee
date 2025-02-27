/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/20 21:48:30 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 리스트 내 최댓값의 비트 수 계산
static int get_max_bits(t_stack *stack)
{
	int max = 0;
	int bits = 0;
	t_stack *temp = stack;

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

// 특정 숫자의 비트 수 계산
static int get_bit_count(int num)
{
	int bits = 0;
	while (num > 0)
	{
		num >>= 1;
		bits++;
	}
	return bits;
}

// 높은 비트 수를 가진 숫자는 stack_b로 이동
static void bit_grouping(t_stack **a, t_stack **b, int threshold)
{
	int size = ft_lstsize(*a);
	int i = 0;

	while (i < size)
	{
		if (get_bit_count((*a)->num) > threshold)
			pb(a, b);
		else
			ra(a, 1);
		i++;
	}
}

// i번째 비트를 기준으로 stack_b로 이동 또는 회전
static void bit_pass(t_stack **a, t_stack **b, int i, int size)
{
	int j = 0;
	while (j < size)
	{
		if ((((*a)->num >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a, 1);
		j++;
	}
}

// 개선된 radix_sort
void radix_sort(t_stack **a, t_stack **b)
{
	int i;
	int size;
	int max_bits;
	int threshold;

	if (is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	max_bits = get_max_bits(*a);
	threshold = 11;
	bit_grouping(a, b, threshold);
	i = 0;
	while (i < max_bits)
	{
		bit_pass(a, b, i, size);
		while (*b)
			pa(b, a);
		i++;
	}
}
