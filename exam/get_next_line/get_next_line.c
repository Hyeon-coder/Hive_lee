/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:36:31 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/17 12:44:42 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
		str[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(str);
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}

# include <stdio.h>
# include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd = 0;
	char	*line;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
