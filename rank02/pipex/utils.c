/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:41 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/16 20:07:40 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *opt)
{
	write(2, opt, ft_strlen(opt));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static char	**get_env_path(char **envp)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

static char	*get_cmd(char **path, char *cmd)
{
	int		i;
	char	*joined_cmd;
	char	*ret_cmd;

	i = 0;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	joined_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		ret_cmd = ft_strjoin(path[i++], joined_cmd);
		if (access(ret_cmd, X_OK) != -1)
		{
			free(joined_cmd);
			return (ret_cmd);
		}
		free(ret_cmd);
	}
	free(joined_cmd);
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**paths;
	char	**cmd_arg;
	char	*cmd_path;

	if (access(cmd, X_OK) == 0)
		cmd_path = cmd;
	else
	{
		paths = get_env_path(envp);
		if (!paths)
			perror_exit("PATH not found");
		cmd_arg = ft_split(cmd, ' ');
		cmd_path = get_cmd(paths, cmd_arg[0]);
		if (!cmd_path)
			perror_exit("command error");
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		perror_exit("execve error");
}
