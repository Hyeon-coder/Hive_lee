/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:35 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/02 00:00:53 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// DONE : echo, env, export, exit, pwd
// TODO : cd, unset

void	execute(char *line, char ***env)
{
	int		i;
	char	**argv;

	argv = ft_split(line, ' ');
	i = 0;
	while (line[i] != ' ')
		i++;
	if (ft_strncmp(line, "cd", i) == 0)
		ft_cd(argv);
	if (ft_strncmp(line, "echo", i) == 0)
		ft_echo(argv);
	if (ft_strncmp(line, "env", i) == 0)
		ft_env(argv, env);
	if (ft_strncmp(line, "export", i) == 0)
		ft_export(argv, env);
	if (ft_strncmp(line, "pwd", i) == 0)
		ft_pwd(argv);
	if (ft_strncmp(line, "unset", i) == 0)
		ft_unset(argv, env);
	ft_free_2d_array(argv);
}
