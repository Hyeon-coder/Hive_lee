/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:53:16 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/17 22:53:17 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*letter;
	int		i;

	letter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			letter = (char *)(str + i);
			return (letter);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}
