/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:00:35 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 04:00:40 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	open_infile_or_exit(t_pipex *pipex, char *filename)
{
	pipex->infile = open(filename, O_RDONLY);
	if (pipex->infile == -1)
	{
		if (access(filename, F_OK) == -1)
			error_exit(filename, 127);
		else if (access(filename, R_OK) == -1)
			error_exit(filename, 126);
		error_exit(filename, 1);
	}
}

static void	open_outfile_or_exit(t_pipex *pipex, char *filename)
{
	pipex->outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		if (access(filename, F_OK) == -1 || access(filename, W_OK) == -1)
			error_exit(filename, 1);
		error_exit(filename, 1);
	}
}

void	child_process1(t_pipex *pipex, char **av, char **envp)
{
	open_infile_or_exit(pipex, av[1]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		error_exit("dup2", 1);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2", 1);
	close(pipex->fd[0]);
	close(pipex->infile);
	execute(pipex, envp, 1);
}

void	child_process2(t_pipex *pipex, char **av, char **envp)
{
	open_outfile_or_exit(pipex, av[4]);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		error_exit("dup2", 1);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		error_exit("dup2", 1);
	close(pipex->fd[1]);
	close(pipex->outfile);
	execute(pipex, envp, 2);
}
