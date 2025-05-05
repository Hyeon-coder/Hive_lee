/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:36:59 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 03:50:17 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	handle_command_error(t_pipex *pipex, char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	clean_pipex(pipex);
	exit(127);
}

void	execute(t_pipex *pipex, char **envp, int cmd_num)
{
	char	**cmd;
	char	*path;

	if (cmd_num == 1)
	{
		cmd = pipex->cmd1;
		path = pipex->path1;
	}
	else
	{
		cmd = pipex->cmd2;
		path = pipex->path2;
	}
	if (!cmd || !cmd[0])
		handle_command_error(pipex, cmd[0]);
	if (!path)
		handle_command_error(pipex, cmd[0]);
	if (execve(path, cmd, envp) == -1)
		error_exit("execve", 1);
}
