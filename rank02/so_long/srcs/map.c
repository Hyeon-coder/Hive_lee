/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_file(const char *filename)
{
	int		fd;
	char	*buffer;
	char	tmp[1024];
	ssize_t	bytes;
	size_t	total;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nFailed to open map file");
	buffer = (char *)malloc(1);
	if (!buffer)
		error_exit("Error\nmalloc failed");
	buffer[0] = '\0';
	total = 0;
	while ((bytes = read(fd, tmp, 1023)) > 0)
	{
		tmp[bytes] = '\0';
		char *new_buf = malloc(total + bytes + 1);
		if (!new_buf)
			error_exit("Error\nmalloc failed");
		strcpy(new_buf, buffer);
		strcat(new_buf, tmp);
		free(buffer);
		buffer = new_buf;
		total += bytes;
	}
	close(fd);
	return (buffer);
}

void	count_player_and_coins(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coins = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->coins++;
			else if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (map[i][j] == 'E' && game->exit_x == -1)
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

static void	validate_no_empty_lines(char *content)
{
	int	len;
	int	i;

	len = ft_strlen(content);
	if (len == 0 || content[0] == '\n' || content[len - 1] == '\n'
		|| ft_strnstr(content, "\n\n", len))
		error_exit("Error\n");
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n' && content[i + 1] == '\0')
			error_exit("Error\n");
		i++;
	}
}

char	**read_map(const char *filename, t_game *game)
{
	char	*content;
	char	**map;
	int		i;

	content = read_file(filename);
	validate_no_empty_lines(content);
	map = ft_split(content, '\n');
	if (!map)
		error_exit("Error\nFailed to split map");
	free(content);
	i = 0;
	while (map[i])
		i++;
	game->map_height = i;
	game->map_width = ft_strlen(map[0]);
	count_player_and_coins(map, game);
	return (map);
}
