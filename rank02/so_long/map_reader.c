/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:54:21 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/23 20:59:31 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

static void	read_map_lines(char **map, int fd, int height)
{
	int		row;
	char	*line;

	row = 0;
	line = get_next_line(fd);
	while (row < height && line)
	{
		map[row++] = line;
		line = get_next_line(fd);
	}
	map[row] = NULL;
}

char	**read_map(char *filename, int *width, int *height)
{
	int		fd;
	char	**map;

	*height = count_lines(filename);
	if (*height <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (*height + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_map_lines(map, fd, *height);
	*width = 0;
	if (*height > 0 && map[0])
		*width = (int)ft_strlen(map[0]) - 1;
	close(fd);
	return (map);
}
