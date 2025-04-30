/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:30:00 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 20:41:06 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_env_path(char **envp)
{
	char	**paths;

	if (!envp || !*envp)
		return (NULL);
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*try_path(char **path, char *joined_cmd)
{
	int		i;
	char	*ret_cmd;

	i = 0;
	while (path[i])
	{
		ret_cmd = ft_strjoin(path[i++], joined_cmd);
		if (!ret_cmd)
		{
			free(joined_cmd);
			return (NULL);
		}
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

char	*get_cmd(char **path, char *cmd)
{
	char	*joined_cmd;

	if (!cmd || !*cmd)
		return (NULL);
	if (access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	if (!path)
		return (NULL);
	joined_cmd = ft_strjoin("/", cmd);
	if (!joined_cmd)
		return (NULL);
	return (try_path(path, joined_cmd));
}
