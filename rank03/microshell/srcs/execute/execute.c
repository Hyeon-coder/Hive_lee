/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:35 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/06 14:32:52 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// DONE : env, export, pwd
// TODO : cd, unset, exit, echo, 

void	execute(char *line, char ***env)
{
	int		i;
	char	**argv;
	int		exit_code;

	argv = ft_split(line, ' ');
	i = 0;
	exit_code = 0;
	while (line[i] != ' ')
		i++;
	if (ft_strncmp(line, "cd", i) == 0)
		exit_code = ft_cd(argv, env);
	if (ft_strncmp(line, "echo", i) == 0)
		exit_code = ft_echo(argv);
	if (ft_strncmp(line, "env", i) == 0)
		exit_code = ft_env(argv, env);
	if (ft_strncmp(line, "export", i) == 0)
		exit_code = ft_export(argv, env);
	if (ft_strncmp(line, "pwd", i) == 0)
		exit_code = ft_pwd(argv);
	if (ft_strncmp(line, "unset", i) == 0)
		exit_code = ft_unset(argv, env);
	if (ft_strncmp(line, "exit", i) == 0)
		exit_code = ft_exit(argv);
	ft_free_2d_array(argv);
}
