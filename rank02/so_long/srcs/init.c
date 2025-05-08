/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->visited = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coins = 0;
	game->moves = 0;
	game->exit_x = -1;
	game->exit_y = -1;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_exit_open = NULL;
	game->img_coin = NULL;
}

void	init_path_ctx(t_path_ctx *ctx)
{
	ctx->map = NULL;
	ctx->visited = NULL;
	ctx->width = 0;
	ctx->height = 0;
	ctx->player_x = 0;
	ctx->player_y = 0;
	ctx->coin_count = 0;
	ctx->allow_exit = 0;
}
