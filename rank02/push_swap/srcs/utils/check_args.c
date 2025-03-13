/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/13 20:37:55 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Checks duplicates.
	(중복 확인.)
*/
static int	ft_contains(int curr, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == curr)
			return (1);
		i++;
	}
	return (0);
}

/*
	Checks if a string represents a number. (문자열이 숫자인지 확인)
*/
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
	Validates the arguments provided to push_swap.
	(push_swap에 제공된 인자들을 검증)
*/
void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	curr;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		curr = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error", args);
		if (ft_contains(curr, args, i) == 1)
			ft_error("Error", args);
		if (curr < -2147483648 || curr > 2147483647)
			ft_error("Error", args);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
