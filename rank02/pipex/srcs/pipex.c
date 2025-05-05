/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:43 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 20:54:05 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	validate_arguments(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	if (!av[1][0])
	{
		ft_putstr_fd("Error: Empty file name\n", 2);
		exit(1);
	}
	if (!av[2][0] || !av[3][0])
		error_exit("empty command", 127);
}

static void	initialize_and_fork(t_pipex *pipex, char **av, char **envp)
{
	init_pipex(pipex);
	if (pipe(pipex->fd) == -1)
		error_exit("pipe", 1);
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->cmd2 = ft_split(av[3], ' ');
	if (!pipex->cmd1 || !pipex->cmd2)
		error_exit("malloc", 1);
	pipex->path1 = find_path(pipex->cmd1[0], envp);
	pipex->path2 = find_path(pipex->cmd2[0], envp);
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		error_exit("fork", 1);
	if (pipex->pid1 == 0)
		child_process1(pipex, av, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		error_exit("fork", 1);
	if (pipex->pid2 == 0)
		child_process2(pipex, av, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	validate_arguments(ac, av);
	initialize_and_fork(&pipex, av, envp);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(pipex.pid1, &pipex.status1, 0);
	waitpid(pipex.pid2, &pipex.status2, 0);
	clean_pipex(&pipex);
	if (WIFEXITED(pipex.status2))
		exit(WEXITSTATUS(pipex.status2));
	exit(0);
}