/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quoted_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/18 10:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*read_word(const char **p)
{
	size_t	cap;
	size_t	len;
	size_t	old_cap;
	char	*buf;
	char	quote;

	cap = 64;
	len = 0;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	while (**p && !ft_isspace((unsigned char)**p))
	{
		if (**p == '\\' && *(*p + 1))
		{
			(*p)++;
			if (len + 1 >= cap)
			{
				old_cap = cap;
				cap *= 2;
				buf = ft_realloc(buf, old_cap, cap);
				if (!buf)
					return (NULL);
			}
			buf[len++] = *(*p)++;
			continue ;
		}
		if (**p == '"' || **p == '\'')
		{
			quote = *(*p)++;
			while (**p && **p != quote)
			{
				if (len + 1 >= cap)
				{
					old_cap = cap;
					cap *= 2;
					buf = ft_realloc(buf, old_cap, cap);
					if (!buf)
						return (NULL);
				}
				buf[len++] = *(*p)++;
			}
			if (**p == quote)
				(*p)++;
		}
		else
		{
			if (len + 1 >= cap)
			{
				old_cap = cap;
				cap *= 2;
				buf = ft_realloc(buf, old_cap, cap);
				if (!buf)
					return (NULL);
			}
			buf[len++] = *(*p)++;
		}
	}
	buf[len] = '\0';
	return (buf);
}

char	**ft_split_quoted(const char *s)
{
	size_t		wc;
	size_t		i;
	char		**res;
	const char	*p;

	wc = ft_count_words_quoted(s);
	i = 0;
	p = s;
	res = malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < wc)
	{
		while (*p && ft_isspace((unsigned char)*p))
			p++;
		res[i++] = read_word(&p);
		while (*p && ft_isspace((unsigned char)*p))
			p++;
	}
	res[i] = NULL;
	return (res);
}
