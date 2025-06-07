/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:39:26 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/07 16:22:27 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_pwd_error(char **argv)
{
	if (argv[1])
	{
		ft_putstr_fd("pwd: options are not supported\n", 2);
		return (1);
	}
	return (0);
}

int	ft_pwd(char **argv)
{
	char	*path;

	if (ft_pwd_error(argv))
		return (1);
	path = getenv("PWD");
	if (!path)
		return (1);
	printf("%s\n", path);
	return (0);
}
