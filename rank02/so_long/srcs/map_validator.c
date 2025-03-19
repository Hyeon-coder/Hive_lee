/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/19 17:11:33 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

/*
	check_tile - Verifies if a given tile is valid within the map.
	(check_tile - 특정 타일이 맵 내에서 유효한지 확인합니다.)
*/
static void	check_tile(t_game *game, int x, int y, int *flags)
{
	if (game->map[y][x] == 'P')
	{
		flags[0]++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (game->map[y][x] == 'E')
		flags[1]++;
	else if (game->map[y][x] == 'C')
		game->collectibles++;
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
	{
		ft_putstr_fd("Error: Invalid character in map.\n", 2);
		handle_exit();
	}
}

/*
	check_rectangle - Ensures that the map has a rectangular shape.
	(check_rectangle - 맵이 직사각형 형태를 유지하는지 확인합니다.)
*/
static int	check_rectangle(t_game *game)
{
	int	y;
	int	width;

	width = ft_strlen(game->map[0]);
	y = 1;
	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) != width)
			return (ft_putstr_fd("Error: It's not rectangle map.\n", 2), 0);
		y++;
	}
	game->width = width;
	return (1);
}

/*
	check_walls - Verifies that the map is surrounded by walls.
	(check_walls - 맵이 벽으로 완전히 둘러싸여 있는지 확인합니다.)
*/
static int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (ft_putstr_fd("Error: It's not surrounded by walls\n", 2), 0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (ft_putstr_fd("Error: It's not surrounded by walls\n", 2), 0);
		y++;
	}
	return (1);
}

/*
	validate_map_elements - Checks if the map contains the necessary elements.
	(validate_map_elements - 맵에 필요한 요소들이 있는지 확인합니다.)
*/
static int	validate_map_elements(t_game *game, int *flags)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			check_tile(game, x, y, flags);
			x++;
		}
		y++;
	}
	if (flags[0] != 1 || flags[1] != 1 || game->collectibles < 1)
	{
		ft_putstr_fd("Error: Map must have 1 player, 1 exit, \
nand at least 1 collectible.\n", 2);
		return (0);
	}
	return (1);
}

/*
	validate_map - Validates the game map to ensure it meets requirements.
	(validate_map - 게임 맵이 요구사항을 충족하는지 검증합니다.)
*/
int	validate_map(t_game *game)
{
	int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
	game->collectibles = 0;
	if (!check_rectangle(game) || !check_walls(game))
		return (0);
	if (!validate_map_elements(game, flags))
		return (0);
	return (1);
}
