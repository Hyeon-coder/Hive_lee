/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:39:53 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/29 23:11:44 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_n_option(char *s)
{
	int i = 0;

	if (s[0] != '-' || s[1] != 'n')
		return (0);
	i = 1;
	while (s[++i])
		if (s[i] != 'n')
			return (0);
	return (1);
}

int	ft_echo(char **argv)
{
	int	i = 1;
	int	print_nl = 1;

	while (argv[i] && is_n_option(argv[i]))
	{
		print_nl = 0;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (print_nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}