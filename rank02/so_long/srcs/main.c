/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 16:12:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    error_exit_free(const char *msg, void *ptr, t_path_ctx *ctx)
{
    if (ptr)
        free(ptr);
    if (ctx && ctx->map)
        free_map(ctx->map);
    write(2, msg, ft_strlen(msg));
    exit(1);
}

int	exit_hook(t_game *game)
{
	close_game(game);
	return (0);
}

static void	validate_and_load(int argc, char **argv, t_game *game,
	t_path_ctx *ctx)
{
	if (argc != 2)
		error_exit("Error\n");
	init_game(game);
	init_path_ctx(ctx);
	validate_not_directory(argv[1], ctx);
	validate_extension(argv[1], ctx);
	game->map = read_map(argv[1], game, ctx);
	validate_rectangular(game->map, ctx);
	validate_walls(game->map, ctx);
	validate_elements(game->map, ctx);
	validate_path(game, ctx);
}

static void	init_and_run_game(t_game *game, t_path_ctx *ctx)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit_with_ctx("mlx_init failed", ctx);
	game->win = mlx_new_window(game->mlx,
			game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE,
			"So Long");
	if (!game->win)
		error_exit_with_ctx("mlx_new_window failed", ctx);
	load_images(game);
	render_map(game);
	display_move_count(game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, exit_hook, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_path_ctx	ctx;

	validate_and_load(argc, argv, &game, &ctx);
	init_and_run_game(&game, &ctx);
	return (0);
}
