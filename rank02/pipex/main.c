/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:16:03 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/20 16:52:05 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	dup_child_1(char **av, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		perror_exit("infile error\n");
	if (dup2(infile, STDIN_FILENO) == -1)
		perror_exit("dup2 error\n");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror_exit("dup2 error\n");
	close(infile);
	close(fd[0]);
	close(fd[1]);
}

static void	child_process_1(char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror_exit("pipe error\n");
	pid = fork();
	if (pid == -1)
		perror_exit("fork error\n");
	if (pid == 0)
	{
		dup_child_1(av, fd);
		execute(av[2], envp);
	}
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror_exit("dup2 error\n");
	close(fd[0]);
}

static void	child_process_2(char **av, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error\n");
	if (pid == 0)
	{
		outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			perror_exit("outfile error\n");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror_exit("dup2 error\n");
		close(outfile);
		execute(av[3], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		stdin_dup;
	int		stdout_dup;

	stdin_dup = dup(0);
	stdout_dup = dup(1);
	if (ac != 5)
		perror_exit("Follow this : ./pipex file1 cmd1 cmd2 file2\n");
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			child_process_1(av, envp);
		else if (i == 1)
			child_process_2(av, envp);
	}
	dup2(stdin_dup, 0);
	dup2(stdout_dup, 1);
	close(stdin_dup);
	close(stdout_dup);
	i = -1;
	while (++i < 2)
		wait(NULL);
}
