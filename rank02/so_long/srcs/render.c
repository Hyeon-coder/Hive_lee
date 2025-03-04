/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/04 04:09:18 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	put_tile - Draws a specific tile at the given position on the screen.
	(put_tile - 주어진 위치에 특정 타일을 화면에 그립니다.)
*/
void	put_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C' && game->collectibles != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible_before, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible_after, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E' && game->collectibles != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit_close, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit_open, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
}

/*
	render_player - Renders the player character on the screen.
	(render_player - 플레이어 캐릭터를 화면에 렌더링합니다.)
*/
void	render_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

/*
	render_map - Renders game objects on the screen.
	(render_map - 게임 객체를 화면에 렌더링합니다.)
*/
void	render_map(t_game *game)
{
	int	x;
	int	y;

	if (!game->mlx || !game->win || !game->map)
	{
		ft_putstr_fd("Error: Null reference in game structure\n", 2);
		return ;
	}
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_player(game);
}
