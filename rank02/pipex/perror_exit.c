/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:42 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 19:46:46 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	print_error(char *prefix, char *msg)
{
	char	*error;

	error = strerror(errno);
	write(2, "pipex: ", 7);
	if (prefix)
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, ": ", 2);
	}
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, ": ", 2);
	}
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	perror_exit(char *opt, int exit_code, int *fd)
{
	if (fd)
	{
		if (fd[0] != -1)
			close(fd[0]);
		if (fd[1] != -1)
			close(fd[1]);
	}
	print_error(NULL, opt);
	exit(exit_code);
}
