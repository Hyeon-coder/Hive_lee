/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:38:12 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/27 17:09:18 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	cnt_deli(char const *s, char c)
{
	size_t	cnt;

	if (!*s)
		return (0);
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			cnt++;
		while (*s != c && *s)
			s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	w_len;
	char	**arr;

	arr = (char **)malloc((cnt_deli(s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				w_len = ft_strlen(s);
			else
				w_len = ft_strchr(s, c) - s;
			arr[i++] = ft_substr(s, 0, w_len);
			s += w_len;
		}
	}
	arr[i] = NULL;
	return (arr);
}
