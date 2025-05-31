/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:35 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/29 23:11:33 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	is_builtin(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] != ' ')
// 		i++;
// 	if (ft_strncmp(line, "cd", i) == 0)
// 		ft_cd(line);
// 	if (ft_strncmp(line, "echo", i) == 0)
// 		ft_echo(line);
// 	if (ft_strncmp(line, "env", i) == 0)
// 		ft_env(line);
// 	if (ft_strncmp(line, "exit", i) == 0)
// 		ft_exit(line);
// 	if (ft_strncmp(line, "export", i) == 0)
// 		ft_export(line);
// 	if (ft_strncmp(line, "pwd", i) == 0)
// 		ft_pwd(line);
// 	if (ft_strncmp(line, "unset", i) == 0)
// 		ft_unset(line);
// 	return (0);
// }

void	execute(char *line)
{
	// is_builtin(line);
	int 	i;
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
		ft_env(argv);
	if (ft_strncmp(line, "exit", i) == 0)
		ft_exit(argv);
	if (ft_strncmp(line, "export", i) == 0)
		ft_export(argv);
	if (ft_strncmp(line, "pwd", i) == 0)
		ft_pwd(argv);
	if (ft_strncmp(line, "unset", i) == 0)
		ft_unset(argv);
		
}