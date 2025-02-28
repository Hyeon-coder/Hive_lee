/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:21:26 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/27 17:09:49 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rst;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i <= j)
		i++;
	if (i > j)
		return (ft_strdup(s1 + j + 1));
	while (ft_strchr(set, s1[j]) && j >= 0)
		j--;
	rst = malloc(j - i + 2);
	if (!rst)
		return (NULL);
	ft_strlcpy(rst, &s1[i], j - i + 2);
	return (rst);
}
