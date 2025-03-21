/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:41 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/20 17:48:21 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	perror_exit(char *opt)
{
	write(2, opt, ft_strlen(opt));
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
			perror_exit("PATH not found\n");
		cmd_arg = ft_split(cmd, ' ');
		cmd_path = get_cmd(paths, cmd_arg[0]);
		if (!cmd_path)
		{
			ft_free(cmd_arg);
			free(cmd_arg);
			ft_free(paths);
			free(paths);
			perror_exit("command error\n");
		}
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		perror_exit("execve error\n");
}
