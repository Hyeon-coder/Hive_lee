/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:10:12 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/03 15:14:15 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	for_split(char *arg, char **args, long tmp, int i)
{
	args = ft_split(arg, ' ');
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error(args, "Error");
		if (ft_contains(tmp, args, i))
			ft_error(args, "Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error(args, "Error");
		i++;
	}
	ft_free(args);
	free(args);
}

static void	for_normal(char **argv, char **args, long tmp, int i)
{
	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error(NULL, "Error");
		if (ft_contains(tmp, args, i))
			ft_error(NULL, "Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error(NULL, "Error");
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;
	char	*arg;

	args = NULL;
	arg = argv[1];
	i = 0;
	tmp = 0;
	if (argc == 2)
	{
		if (argv[1] == NULL)
		{
			write(2, "Error\n", 6);
			return ;
		}
		for_split(arg, args, tmp, i);
	}
	else
		for_normal(argv, args, tmp, i);
}
