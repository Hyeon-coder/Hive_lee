/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:53:26 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/17 22:53:27 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*start;
	int		i;
	int		len;

	len = ft_strlen(s1);
	start = malloc(len + 1);
	if (!start)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		start[i] = s1[i];
		i++;
	}
	start[i] = 0;
	return (start);
}
