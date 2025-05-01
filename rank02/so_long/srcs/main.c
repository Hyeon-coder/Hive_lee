#include "../includes/so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX initialization failed");
	game->tile_size = TILE_SIZE;
	game->moves = 0;
	game->map = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
}

static void	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx,
			game->width * game->tile_size,
			game->height * game->tile_size,
			"So Long!");
	if (!game->win)
		error_exit("Window creation failed");
	load_images(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map_file>");
	init_game(&game);
	game.map = read_map(argv[1], &game.width, &game.height);
	if (!game.map)
	{
		cleanup_game(&game);
		error_exit("Failed to read map");
	}
	if (!validate_map(&game))
	{
		cleanup_game(&game);
		error_exit(NULL);
	}
	start_game(&game);
	return (0);
} 