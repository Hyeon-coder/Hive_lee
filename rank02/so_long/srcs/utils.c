/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Error\nmalloc failed");
	return (ptr);
}

int	is_valid_extension(const char *filename, const char *ext)
{
	size_t	len_filename;
	size_t	len_ext;

	len_filename = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_filename < len_ext)
		return (0);
	return (ft_strncmp(filename + len_filename - len_ext, ext, len_ext) == 0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	check_tile(char tile, int x, int y, t_game *game)
{
	if (tile == 'C')
		game->coins++;
	else if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'E' && game->exit_x == -1)
	{
		game->exit_x = x;
		game->exit_y = y;
	}
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
			check_tile(map[i][j], j, i, game);
			j++;
		}
		i++;
	}
}
