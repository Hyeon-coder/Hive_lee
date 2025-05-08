/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_exit(t_game *game)
{
	return (game->coins <= 0);
}

void	close_game(t_game *g)
{
	if (g->map)
		free_split(g->map);
	if (g->visited)
		free_visited(g->visited, g->map_height);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_coin)
		mlx_destroy_image(g->mlx, g->img_coin);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_exit_open)
		mlx_destroy_image(g->mlx, g->img_exit_open);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_loop_end(g->mlx);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
}

void	error_exit_with_ctx(const char *msg, t_path_ctx *ctx)
{
	if (ctx && ctx->map)
		free_split(ctx->map);
	ft_putstr_fd((char *)msg, 2);
	exit(EXIT_FAILURE);
}

void	error_exit(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_visited(int **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
