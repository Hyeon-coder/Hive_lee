/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:44:27 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/06 14:31:45 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_str_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (('a' <= str[i] && str[i] <= 'z')
			|| ('A' <= str[i] && str[i] <= 'Z'))
			return (TRUE);
	}
	return (FALSE);
}

/*
	too many argu => don't quit minishell
	others => need quit
*/
int exit_error(char **argv)
{
	int cnt;
	
	cnt = 0;
	while (argv[cnt])
		cnt++;
	if (2 < cnt)
	{
		ft_error("exit: too many arguments\n");
		return (1);
	}
	else if (ft_str_isalpha(argv[1]))
	{
		ft_error("exit: ");
		ft_error(argv[1]);
		ft_error("numeric argument required\n");
		return (2);
	}
	else
	{
		ft_error("exit: unknown error\n");
		return (1);
	}
	return (0);
		
}

int	ft_exit(char **argv)
{
	int	exit_code;

	exit_code = 0;
	exit_code = exit_error(argv);
	// re-initialize use by exit_code
	// and return that?
	if (exit_code != 0)
		return (exit_code);
	printf("eeeeexit\n");
	return (exit_code);
}
