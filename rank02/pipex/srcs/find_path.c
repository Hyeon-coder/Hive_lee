/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:36:40 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/05 03:51:44 by juhyeonl         ###   ########.fr       */
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
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	*found;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i] + 5;
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
