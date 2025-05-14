/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:36:59 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/14 17:31:22 by juhyeonl         ###   ########.fr       */
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
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": Is a directory\n", 17);
		clean_pipex(pipex);
		exit(126);
	}
	if (access(path, X_OK) == -1)
	{
		write(2, "Permission denied: ", 20);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		clean_pipex(pipex);
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
		handle_command_error(pipex, "");
	}
	if (!path)
		handle_command_error(pipex, cmd[0]);
	if (execve(path, cmd, envp) == -1)
		handle_execve_error(pipex, path, cmd[0]);
}
