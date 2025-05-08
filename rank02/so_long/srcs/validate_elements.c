/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	validate_tile_char(char tile, t_path_ctx *ctx)
{
	if (!ft_strchr("01PEC", tile))
		safe_print_map_error(ctx);
}

static void	count_map_elements(char tile, int *p, int *e, int *c)
{
	if (tile == 'P')
		(*p)++;
	else if (tile == 'E')
		(*e)++;
	else if (tile == 'C')
		(*c)++;
}

void	validate_elements(char **map, t_path_ctx *ctx)
{
	int	y;
	int	x;
	int	player_count;
	int	exit_count;
	int	coin_count;

	y = 0;
	player_count = 0;
	exit_count = 0;
	coin_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			validate_tile_char(map[y][x], ctx);
			count_map_elements(map[y][x],
				&player_count, &exit_count, &coin_count);
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1 || coin_count < 1)
		safe_print_map_error(ctx);
}
