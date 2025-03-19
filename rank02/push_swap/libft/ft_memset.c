/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:49 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/19 15:50:21 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i++ < len)
		*ptr++ = (unsigned char)c;
	return (b);
}
