/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:01:42 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/04/30 20:54:05 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	int		status;

	if (ac != 5)
	{
		write(2, "Error: Invalid number of arguments\n", 34);
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		return (1);
	}
	if (pipe(fd) == -1)
		perror_exit("pipe", 1, fd);
	child_process_1(av, envp, fd);
	child_process_2(av, envp, fd);
	close_fds(fd, -1, -1);
	while (waitpid(-1, &status, 0) > 0)
		continue;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
