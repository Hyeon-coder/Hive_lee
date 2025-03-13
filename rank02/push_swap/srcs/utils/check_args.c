/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/14 01:12:37 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	메모리 해제 함수 (ft_split로 분리한 배열을 해제)
*/
void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/*
	Checks if a string represents a valid number. (문자열이 유효한 숫자인지 확인)
*/
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i] == ' ' || num[i] == '\t')
		i++;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (num[i] == '\0')
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
	Checks for duplicate numbers. (중복된 숫자가 있는지 확인)
*/
static int	ft_contains(int num, char **argv, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(argv[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

/*
	Validates and processes arguments. (인자 검증 및 처리)
*/
static void	process_args(char **args)
{
	int	i;
	int	num;

	i = 0;
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			ft_error(args);
		num = ft_atoi_with_free(args, args[i]);
		if (ft_contains(num, args, i))
			ft_error(args);
		i++;
	}
}

/*
	Validates all arguments. (모든 인자를 검증하고 잘못된 입력이면 프로그램 종료)
*/
void	ft_check_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			ft_error(args);
		process_args(args);
		ft_free_args(args);
	}
	else
		process_args(argv + 1);
}
