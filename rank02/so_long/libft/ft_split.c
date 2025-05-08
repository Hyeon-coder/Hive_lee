/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 06:26:29 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/08 06:26:31 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(void **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_fill_array(char **array, const char *s, char c, size_t w_count)
{
	size_t		i;
	const char	*start;
	const char	*end;

	i = 0;
	start = s;
	while (i < w_count)
	{
		while (*start == c)
			start++;
		end = start;
		while (*end && *end != c)
			end++;
		array[i] = ft_substr(start, 0, end - start);
		if (!array[i])
		{
			ft_free_array((void **)array, i);
			return (0);
		}
		start = end;
		i++;
	}
	array[i] = NULL;
	return (1);
}

void	free_split(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	w_count;

	if (!s)
		return (NULL);
	w_count = ft_word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!array)
		return (NULL);
	if (!ft_fill_array(array, s, c, w_count))
		return (NULL);
	return (array);
}
