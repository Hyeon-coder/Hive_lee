/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	next_tile;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	next_tile = game->map[ny][nx];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E' && !can_exit(game))
		return ;
	if (next_tile == 'C')
		game->coins--;
	if (next_tile == 'E' && can_exit(game))
	{
		printf("You win!\n");
		close_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[ny][nx] = 'P';
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;
	render_map(game);
	display_move_count(game);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		close_game(game);
	else if (keycode == 'w' || keycode == 13
		|| keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == 1
		|| keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == 0
		|| keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == 2
		|| keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
