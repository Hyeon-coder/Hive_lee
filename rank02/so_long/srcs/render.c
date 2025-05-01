#include "../includes/so_long.h"

static void	load_image(t_game *game, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!*img)
		error_exit("Failed to load image");
}

void	load_images(t_game *game)
{
	load_image(game, &game->img_wall, "textures/wall.xpm");
	load_image(game, &game->img_player, "textures/chara.xpm");
	load_image(game, &game->img_collectible, "textures/chest.xpm");
	load_image(game, &game->img_exit, "textures/rune.xpm");
	load_image(game, &game->img_floor, "textures/land.xpm");
}

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->tile_size, y * game->tile_size);
}

static void	render_tile(t_game *game, int x, int y)
{
	put_image(game, game->img_floor, x, y);
	if (game->map[y][x] == WALL)
		put_image(game, game->img_wall, x, y);
	else if (game->map[y][x] == COLLECTIBLE)
		put_image(game, game->img_collectible, x, y);
	else if (game->map[y][x] == EXIT)
		put_image(game, game->img_exit, x, y);
	else if (game->map[y][x] == PLAYER)
		put_image(game, game->img_player, x, y);
}

static void	render_text(t_game *game)
{
	char	*collectibles;
	char	*moves;
	char	*collectibles_text;
	char	*moves_text;

	collectibles = ft_itoa(game->collectibles);
	moves = ft_itoa(game->moves);
	collectibles_text = ft_strjoin("Collectibles: ", collectibles);
	moves_text = ft_strjoin("Moves: ", moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, collectibles_text);
	mlx_string_put(game->mlx, game->win, 10, 40, 0xFFFFFF, moves_text);
	free(collectibles);
	free(moves);
	free(collectibles_text);
	free(moves_text);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_text(game);
} 