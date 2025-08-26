/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:59:40 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/08/25 17:01:39 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "gnl.h"

char	*get_next_line(int fd)
{
	char	*str = malloc(BUFFER_SIZE);
	char	c;
	int	i = 0;
	int	cpt = 0;

	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		
	}
}
