/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:53:11 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/02 14:38:34 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(void **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

static size_t	ft_w_count(const char *str, char c)
{
	size_t	w_count;

	w_count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			w_count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (w_count);
}

static void	ft_fill_array(char **array, const char *s, char c, size_t w_count)
{
	const char	*start;
	const char	*end;
	size_t		i;

	start = s;
	i = 0;
	while (i < w_count)
	{
		while (*start == c)
			start++;
		end = ft_strchr(start, c);
		if (!end)
			end = start + ft_strlen(start);
		array[i] = ft_substr(start, 0, end - start);
		if (!array[i])
		{
			ft_free_array((void **)array, i);
		}
		start = end + (*end == c);
		i++;
	}
	array[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char		**array;
	size_t		w_count;

	if (!s)
		return (NULL);
	w_count = ft_w_count(s, c);
	array = (char **)ft_calloc(w_count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	ft_fill_array(array, s, c, w_count);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
