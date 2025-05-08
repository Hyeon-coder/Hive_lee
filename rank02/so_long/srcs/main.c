/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coins = 0;
	game->moves = 0;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_exit_open = NULL;
	game->img_coin = NULL;
	game->exit_x = -1;
	game->exit_y = -1;
}

int	exit_hook(t_game *game)
{
	close_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	validate_not_directory(argv[1]);
	validate_extension(argv[1]);
	init_game(&game);
	game.map = read_map(argv[1], &game);
	validate_rectangular(game.map);
	validate_walls(game.map);
	validate_elements(game.map);
	validate_path(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit("mlx_init failed");
	game.win = mlx_new_window(game.mlx,
			game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE,
			"So Long");
	if (!game.win)
		error_exit("mlx_new_window failed");
	load_images(&game);
	render_map(&game);
	display_move_count(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
