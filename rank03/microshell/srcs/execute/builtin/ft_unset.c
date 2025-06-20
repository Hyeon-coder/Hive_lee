/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:39:31 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/07 18:37:38 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
	
*/

int	ft_unset(char **argv, t_env *env_list)
{
	int		i;
	int		j;
	size_t	name_len;
	char	**envp;

	if (!argv[1])
		return (0);
	// envp = *env;
	envp = NULL;
	(void)env_list;
	i = 1;
	while (argv[i])
	{
		name_len = ft_strlen(argv[i]);
		j = 0;
		while (envp[j])
		{
			if (ft_strncmp(envp[j], argv[i], name_len) == 0
				&& envp[j][name_len] == '=')
			{
				free(envp[j]);
				while (envp[j + 1])
				{
					envp[j] = envp[j + 1];
					j++;
				}
				envp[j] = NULL;
				continue ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
