/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:54:21 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/06 06:54:52 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	count_lines - Counts the number of lines in the map file.
	(count_lines - 맵 파일에서 줄 수를 계산합니다.)
*/
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
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

/*
	read_map_lines - Reads individual lines of the map from a file.
	(read_map_lines - 파일에서 맵의 각 줄을 읽어옵니다.)
*/
static void	read_map_lines(char **map, int fd, int height)
{
	int		row;
	char	*line;

	row = 0;
	line = get_next_line(fd);
	while (row < height && line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[row++] = line;
		line = get_next_line(fd);
	}
	map[row] = NULL;
}

/*
	read_map - Reads the game map from a file and loads it into memory.
	(read_map - 파일에서 게임 맵을 읽어와 메모리에 로드합니다.)
*/
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
	close(fd);
	*width = ft_strlen(map[0]);
	return (map);
}
