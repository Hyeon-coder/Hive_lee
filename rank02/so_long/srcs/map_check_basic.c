/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	safe_print_map_error(t_path_ctx *ctx)
{
	int	i;

	if (ctx->visited)
	{
		i = 0;
		while (i < ctx->height)
			free(ctx->visited[i++]);
		free(ctx->visited);
	}
	if (ctx->map)
		free_split(ctx->map);
	write(2, "Error\n", 6);
	exit(1);
}

void	validate_not_directory(const char *filename, t_path_ctx *ctx)
{
	struct stat	path_stat;

	if (stat(filename, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
		safe_print_map_error(ctx);
}

void	validate_extension(const char *filename, t_path_ctx *ctx)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		safe_print_map_error(ctx);
}

void	validate_rectangular(char **map, t_path_ctx *ctx)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (width == 0 || (int)ft_strlen(map[i]) != width)
			safe_print_map_error(ctx);
		i++;
	}
}

void	validate_walls(char **map, t_path_ctx *ctx)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			safe_print_map_error(ctx);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			safe_print_map_error(ctx);
		y++;
	}
}
