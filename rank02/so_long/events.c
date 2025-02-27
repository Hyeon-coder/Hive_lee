/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:42 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/23 21:07:21 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_move_and_count(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[new_y][new_x] = 'P';
		render_map(game);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		write(1, "\n", 1);
		if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
		{
			ft_putstr_fd("Congratulations! You've won the game.\n", 1);
			exit(0);
		}
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == 65307)
		exit(0);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 119 || keycode == 65362)
		new_y--;
	else if (keycode == 115 || keycode == 65364)
		new_y++;
	else if (keycode == 97 || keycode == 65361)
		new_x--;
	else if (keycode == 100 || keycode == 65363)
		new_x++;
	handle_move_and_count(game, new_x, new_y);
	return (0);
}

int	handle_resize(int width, int height, t_game *game)
{
	(void)width;
	(void)height;
	render_map(game);
	return (0);
}
