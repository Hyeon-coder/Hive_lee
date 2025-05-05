/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:35:21 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 03:39:22 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	init_pipex(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->status1 = 0;
	pipex->status2 = 0;
}

void	clean_pipex(t_pipex *pipex)
{
	if (pipex->cmd1)
		ft_free(pipex->cmd1);
	if (pipex->cmd2)
		ft_free(pipex->cmd2);
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->path2)
		free(pipex->path2);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
}

void	error_exit(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}
