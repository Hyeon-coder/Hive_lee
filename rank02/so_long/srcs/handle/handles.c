/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:00:00 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/04 04:12:09 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
	handle_expose - Handles window expose events.
	(handle_expose - 창 노출(갱신) 이벤트를 처리합니다.)
*/
int	handle_expose(t_game *game)
{
	render_map(game);
	return (0);
}

/*
	handle_collectible - Updates collectible items when collected.
	(handle_collectible - 수집품을 획득할 때 상태를 업데이트합니다.)
*/
void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
		if (game->collectibles == 0)
			render_map(game);
	}
}

/*
	handle_exit_game - Properly exits the game and cleans up resources.
	(handle_exit_game - 게임을 정상적으로 종료하고 리소스를 정리합니다.)
*/
void	handle_exit_game(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->collectibles == 0)
	{
		ft_printf("Congratulations! You Won!\n");
		exit(0);
	}
}

/*
	handle_exit - Handles game exit events.
	(handle_exit - 게임 종료 이벤트를 처리합니다.)
*/
int	handle_exit(void)
{
	ft_printf("Game Over! Thanks for playing.\n");
	exit(0);
	return (0);
}
