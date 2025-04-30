/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:01:42 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/04/30 16:34:50 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	dup_child_1(char **av, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		perror_exit("infile", 1, fd);
	if (dup2(infile, STDIN_FILENO) == -1)
		perror_exit("dup2 infile", 1, fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror_exit("dup2 pipe write", 1, fd);
	close(infile);
	close(fd[0]);
	close(fd[1]);
}

static pid_t	child_process_1(char **av, char **envp, int *fd)
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

static pid_t	child_process_2(char **av, char **envp, int *fd)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		perror_exit("fork", 1, fd);
	if (pid == 0)
	{
		outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			perror_exit("outfile", 1, fd);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror_exit("dup2 pipe read", 1, fd);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror_exit("dup2 outfile", 1, fd);
		close(outfile);
		close(fd[0]);
		close(fd[1]);
		execute(av[3], envp, fd);
	}
	return (pid);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (ac != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		return (1);
	}
	if (pipe(fd) == -1)
		perror_exit("pipe", 1, fd);
	pid1 = child_process_1(av, envp, fd);
	pid2 = child_process_2(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
