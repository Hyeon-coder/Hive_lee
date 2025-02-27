/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/23 21:01:04 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_tile(t_game *game, int x, int y, int *flags)
{
	if (game->map[y][x] == 'P')
	{
		flags[0] = 1;
		game->player_x = x;
		game->player_y = y;
	}
	else if (game->map[y][x] == 'E')
		flags[1] = 1;
}

int	validate_map(t_game *game)
{
	int	x;
	int	y;
	int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
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
	if (flags[0] && flags[1])
		return (1);
	return (0);
}
