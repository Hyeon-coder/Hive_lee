#include "../includes/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == WALL)
		return ;
	if (game->map[new_y][new_x] == EXIT)
	{
		if (game->collectibles > 0)
			return ;
		ft_putstr_fd("You win!\n", 1);
		handle_exit(game);
	}
	if (game->map[new_y][new_x] == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
	game->map[game->player_y][game->player_x] = FLOOR;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = PLAYER;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		handle_exit(game);
	else if (keycode == 119 || keycode == 65362) // W or Up
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115 || keycode == 65364) // S or Down
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97 || keycode == 65361) // A or Left
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100 || keycode == 65363) // D or Right
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

int	handle_exit(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
} 