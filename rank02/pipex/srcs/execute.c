/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:36:59 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 04:29:42 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	select_cmd_and_path(t_pipex *pipex, int cmd_num, char ***cmd
, char **path)
{
	if (cmd_num == 1)
	{
		*cmd = pipex->cmd1;
		*path = pipex->path1;
	}
	else
	{
		*cmd = pipex->cmd2;
		*path = pipex->path2;
	}
}

static void	handle_command_error(t_pipex *pipex, char *cmd)
{
	if (cmd && *cmd)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
	}
	clean_pipex(pipex);
	exit(127);
}

static void	handle_execve_error(t_pipex *pipex, char *path, char *cmd)
{
	clean_pipex(pipex);
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	handle_command_error(pipex, cmd);
}

void	execute(t_pipex *pipex, char **envp, int cmd_num)
{
	char	**cmd;
	char	*path;

	select_cmd_and_path(pipex, cmd_num, &cmd, &path);
	if (!cmd || !cmd[0] || !cmd[0][0])
	{
		clean_pipex(pipex);
		exit(0);
	}
	if (!path)
		handle_command_error(pipex, cmd[0]);
	if (execve(path, cmd, envp) == -1)
		handle_execve_error(pipex, path, cmd[0]);
}
