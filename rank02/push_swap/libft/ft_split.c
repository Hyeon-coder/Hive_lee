/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:53:11 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/19 15:38:11 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	word_count(char const *s, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// int	word_length(char const *s, char c)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (s[i] != c && s[i] != '\0')
// 	{
// 		i++;
// 		len++;
// 	}
// 	return (len);
// }

// char	**f(char const *s, char c, char **result, int words_count)
// {
// 	int	i;
// 	int	j;
// 	int	w_len;

// 	while (*s == c)
// 		s++;
// 	i = -1;
// 	while (++i < words_count)
// 	{
// 		while (*s == c)
// 			s++;
// 		j = 0;
// 		w_len = word_length(s, c);
// 		result[i] = (char *)malloc(sizeof(char) * (w_len + 1));
// 		if (!(result[i]))
// 			return (NULL);
// 		while (j < w_len)
// 		{
// 			result[i][j] = *s;
// 			s++;
// 			j++;
// 		}
// 		result[i][j] = '\0';
// 	}
// 	return (result);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**result;
// 	int		wcount;

// 	if (!s)
// 		return (NULL);
// 	wcount = word_count(s, c);
// 	result = (char **)malloc(sizeof(char *) * (wcount + 1));
// 	if (!(result))
// 		return (NULL);
// 	result = f(s, c, result, wcount);
// 	result[wcount] = NULL;
// 	return (result);
// }
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

static int	ft_fill_array(char **array, const char *s, char c, size_t w_count)
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
			return (0);
		}
		start = end + (*end == c);
		i++;
	}
	array[i] = NULL;
	return (1);
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
	if (!ft_fill_array(array, s, c, w_count))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
