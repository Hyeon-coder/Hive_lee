/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_tile(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			PATH_WALL, &width, &height);
	if (!game->img_wall)
		error_exit("Error\nFailed to load wall image");
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			PATH_FLOOR, &width, &height);
	if (!game->img_floor)
		error_exit("Error\nFailed to load floor image");
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			PATH_PLAYER, &width, &height);
	if (!game->img_player)
		error_exit("Error\nFailed to load player image");
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			PATH_EXIT, &width, &height);
	if (!game->img_exit)
		error_exit("Error\nFailed to load exit image");
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
			PATH_COIN, &width, &height);
	if (!game->img_coin)
		error_exit("Error\nFailed to load coin image");
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			PATH_EXIT_OPEN, &width, &height);
	if (!game->img_exit_open)
		error_exit("Error\nFailed to load open exit image");
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			if (tile == '1')
				draw_tile(game, x, y, game->img_wall);
			else
				draw_tile(game, x, y, game->img_floor);
			if (tile == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				draw_tile(game, x, y, game->img_player);
			}
			else if (tile == 'C')
				draw_tile(game, x, y, game->img_coin);
			else if (tile == 'E')
			{
				if (can_exit(game))
					draw_tile(game, x, y, game->img_exit_open);
				else
					draw_tile(game, x, y, game->img_exit);
			}
			x++;
		}
		y++;
	}
}

void	display_move_count(t_game *game)
{
	char	*str;
	char	*count;

	count = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
	printf("Moves: %d\n", game->moves);
	free(str);
	free(count);
}
