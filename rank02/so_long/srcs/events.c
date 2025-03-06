/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:00:00 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/06 06:40:43 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	handle_move_and_count - Moves the player and updates movement count.
	(handle_move_and_count - 플레이어를 이동시키고 이동 횟수를 업데이트합니다.)
*/
static void	handle_move_and_count(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	next_pos = game->map[new_y][new_x];
	if (next_pos == '1' || (next_pos == 'E' && game->collectibles > 0))
		return ;
	if (next_pos == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	render_map(game);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	if (next_pos == 'E' && game->collectibles == 0)
	{
		ft_printf("Congratulations! You've won the game.\n");
		exit(0);
	}
}

/*
	handle_keypress - Handles keyboard inputs for player movement.
	(handle_keypress - 플레이어 이동을 위한 키보드 입력을 처리합니다.)
*/
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
	if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100
		|| keycode == 65362 || keycode == 65364
		|| keycode == 65361 || keycode == 65363)
	{
		handle_move_and_count(game, new_x, new_y);
	}
	return (0);
}

/*
	handle_resize - Handles window resizing events.
	(handle_resize - 창 크기 조정 이벤트를 처리합니다.)
*/
int	handle_resize(t_game *game, int width, int height)
{
	(void)width;
	(void)height;
	render_map(game);
	return (0);
}
