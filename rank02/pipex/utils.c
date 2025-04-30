/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:41 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 20:54:37 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static void	cleanup_and_exit(char **cmd_arg, char **paths,
	char *cmd_path, int *fd)
{
	if (cmd_arg)
		ft_free(cmd_arg);
	if (paths)
		ft_free(paths);
	if (cmd_path)
		free(cmd_path);
	perror_exit("execve failed", 126, fd);
}

static void	check_cmd_access(char *cmd_path, char **cmd_arg,
	char **paths, int *fd)
{
	struct stat	st;

	if (stat(cmd_path, &st) == -1)
	{
		ft_free(cmd_arg);
		if (paths)
			ft_free(paths);
		perror_exit("command not found", 127, fd);
	}
	if (!(st.st_mode & S_IXUSR))
	{
		ft_free(cmd_arg);
		if (paths)
			ft_free(paths);
		free(cmd_path);
		perror_exit("Permission denied", 126, fd);
	}
}

void	execute(char *cmd, char **envp, int *fd)
{
	char	**paths;
	char	**cmd_arg;
	char	*cmd_path;

	if (!cmd || !*cmd)
		perror_exit("command not found", 127, fd);
	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg || !cmd_arg[0])
	{
		if (cmd_arg)
			ft_free(cmd_arg);
		perror_exit("command not found", 127, fd);
	}
	paths = get_env_path(envp);
	cmd_path = get_cmd(paths, cmd_arg[0]);
	if (!cmd_path)
	{
		ft_free(cmd_arg);
		if (paths)
			ft_free(paths);
		perror_exit("command not found", 127, fd);
	}
	check_cmd_access(cmd_path, cmd_arg, paths, fd);
	if (execve(cmd_path, cmd_arg, envp) == -1)
		cleanup_and_exit(cmd_arg, paths, cmd_path, fd);
}
