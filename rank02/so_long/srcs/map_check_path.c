/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 16:30:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	dfs(t_path_ctx *ctx, int x, int y)
{
	if (ctx->map[y][x] == '1' || ctx->visited[y][x]
		|| (ctx->map[y][x] == 'E' && !ctx->allow_exit))
		return ;
	ctx->visited[y][x] = 1;
	if (x > 0)
		dfs(ctx, x - 1, y);
	if (ctx->map[y][x + 1])
		dfs(ctx, x + 1, y);
	if (y > 0)
		dfs(ctx, x, y - 1);
	if (ctx->map[y + 1])
		dfs(ctx, x, y + 1);
}

static void	init_visited(t_path_ctx *ctx)
{
	int	y;

	ctx->visited = malloc(sizeof(int *) * ctx->height);
	if (!ctx->visited)
		safe_print_map_error(ctx);
	y = 0;
	while (y < ctx->height)
	{
		ctx->visited[y] = ft_calloc(ctx->width, sizeof(int));
		if (!ctx->visited[y])
			safe_print_map_error(ctx);
		y++;
	}
}

static void	check_all_coins(t_game *g, t_path_ctx *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->height)
	{
		x = 0;
		while (x < ctx->width)
		{
			if (g->map[y][x] == 'C' && !ctx->visited[y][x])
				safe_print_map_error(ctx);
			x++;
		}
		ft_bzero(ctx->visited[y], sizeof(int) * ctx->width);
		y++;
	}
}

static void	check_exit_reachable(t_game *g, t_path_ctx *ctx)
{
	ctx->allow_exit = 1;
	dfs(ctx, g->player_x, g->player_y);
	if (!ctx->visited[g->exit_y][g->exit_x])
		safe_print_map_error(ctx);
}

void	validate_path(t_game *g, t_path_ctx *ctx)
{
	int	i;

	ctx->map = g->map;
	ctx->height = g->map_height;
	ctx->width = g->map_width;
	ctx->player_x = g->player_x;
	ctx->player_y = g->player_y;
	ctx->allow_exit = 0;
	init_visited(ctx);
	dfs(ctx, g->player_x, g->player_y);
	check_all_coins(g, ctx);
	check_exit_reachable(g, ctx);
	i = 0;
	while (i < ctx->height)
		free(ctx->visited[i++]);
	free(ctx->visited);
	ctx->visited = NULL;
}
