/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:57:45 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/04/30 15:12:40 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	perror_exit(char *opt, int exit_code, int *fd)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (fd[i] > 2)
			close(fd[i]);
		i++;
	}
	if (opt)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(opt);
	}
	exit(exit_code);
}
