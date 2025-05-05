/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:36:40 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 04:32:35 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*join_and_check(char *path, int len, char *cmd)
{
	char	*dir;
	char	*bin;
	char	*full_path;

	dir = ft_substr(path, 0, len);
	if (!dir)
		return (NULL);
	bin = ft_strjoin(dir, "/");
	free(dir);
	if (!bin)
		return (NULL);
	full_path = ft_strjoin(bin, cmd);
	free(bin);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*check_absolute_path(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

static char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

static char	*search_paths(char *path, char *cmd)
{
	char	*found;
	int		i;

	while (*path)
	{
		i = 0;
		while (path[i] && path[i] != ':')
			i++;
		found = join_and_check(path, i, cmd);
		if (found)
			return (found);
		path += i;
		if (*path)
			path++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	*found;

	if (!cmd || !cmd[0])
		return (NULL);
	found = check_absolute_path(cmd);
	if (found)
		return (found);
	path = get_env_path(envp);
	if (!path)
		return (NULL);
	return (search_paths(path, cmd));
}
