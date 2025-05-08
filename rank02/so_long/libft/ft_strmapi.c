/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:53:46 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/17 22:53:47 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*st;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	st = malloc(size + 1);
	if (!st)
		return (0);
	ft_strlcpy(st, s, size + 1);
	while (i < size)
	{
		st[i] = (*f)(i, st[i]);
		i++;
	}
	return (st);
}
