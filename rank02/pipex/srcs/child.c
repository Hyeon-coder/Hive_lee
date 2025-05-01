/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:00:00 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 20:40:52 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fds(int *fd, int infile, int outfile)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (infile != -1)
		close(infile);
	if (outfile != -1)
		close(outfile);
}

void	dup_child_1(char **av, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		perror_exit(av[1], 1, fd);
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		close_fds(fd, infile, -1);
		perror_exit("dup2", 1, fd);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close_fds(fd, infile, -1);
		perror_exit("dup2", 1, fd);
	}
	close_fds(fd, infile, -1);
}

void	dup_child_2(char **av, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		perror_exit(av[4], 1, fd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close_fds(fd, -1, outfile);
		perror_exit("dup2", 1, fd);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		close_fds(fd, -1, outfile);
		perror_exit("dup2", 1, fd);
	}
	close_fds(fd, -1, outfile);
}

pid_t	child_process_1(char **av, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork", 1, fd);
	if (pid == 0)
	{
		dup_child_1(av, fd);
		execute(av[2], envp, fd);
	}
	return (pid);
}

pid_t	child_process_2(char **av, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork", 1, fd);
	if (pid == 0)
	{
		dup_child_2(av, fd);
		execute(av[3], envp, fd);
	}
	return (pid);
}
