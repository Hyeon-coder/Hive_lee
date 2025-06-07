/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:19:49 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/07 18:41:53 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*env_new(char *env_str)
{
	t_env	*new;
	char	*equal_pos;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	equal_pos = strchr(env_str, '=');
	if (!equal_pos)
		return (free(new), NULL);
	new->name = strndup(env_str, equal_pos - env_str);
	new->value = strdup(equal_pos + 1);
	new->next = NULL;
	return (new);
}

static void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	env_clear(t_env **lst)
{
	t_env	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->name);
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
}

t_env	*env_init(char **envp)
{
	t_env	*env_list;
	t_env	*new;
	int		i = 0;

	env_list = NULL;
	while (envp[i])
	{
		new = env_new(envp[i]);
		if (!new)
		{
			env_clear(&env_list);
			return (NULL);
		}
		env_add_back(&env_list, new);
		i++;
	}
	return (env_list);
}
