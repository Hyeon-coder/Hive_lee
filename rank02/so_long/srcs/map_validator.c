#include "../includes/so_long.h"

static int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != WALL || game->map[game->height - 1][x] != WALL)
			return (0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != WALL || game->map[y][game->width - 1] != WALL)
			return (0);
		y++;
	}
	return (1);
}

static int	check_size(t_game *game)
{
	int max_width;
	int max_height;

	max_width = 1920 / game->tile_size;
	max_height = 1080 / game->tile_size;

	if (game->width > max_width || game->height > max_height)
	{
		ft_putstr_fd("Invalid map : Map is too large for the screen resolution\n", 2);
		return (0);
	}
	return (1);
}

static int	check_characters(t_game *game)
{
	int	x;
	int	y;
	int	player;
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == PLAYER)
			{
				player++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == EXIT)
				exit++;
			else if (game->map[y][x] == COLLECTIBLE)
				collectible++;
			else if (game->map[y][x] != WALL && game->map[y][x] != FLOOR)
				return (0);
		}
	}
	game->collectibles = collectible;
	return (player == 1 && exit == 1 && collectible > 0);
}

static int	check_map_format(t_game *game)
{
	int	i;
	int	len;
	char	*last_line;

	i = 0;
	while (i < game->height)
	{
		if (!game->map[i] || game->map[i][0] == '\0')
			return (0);
		i++;
	}
	last_line = game->map[game->height - 1];
	len = ft_strlen(last_line);
	if (len > 0 && last_line[len - 1] == '\n')
		return (0);
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_walls(game))
	{
		ft_putstr_fd("Invalid map : Map must be surrounded by walls\n", 2);
		return (0);
	}
	if (!check_size(game))
		return (0);
	if (!check_characters(game))
	{
		ft_putstr_fd("Invalid map : Map must have 1 player, 1 exit, and at least 1 collectible\n", 2);
		return (0);
	}
	if (!check_map_format(game))
	{
		ft_putstr_fd("Invalid map : Map must not have empty lines or newlines at the end\n", 2);
		return (0);
	}
	return (1);
} 