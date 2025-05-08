/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_map_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	validate_elements(char **m)
{
	int	y;
	int	x;
	int	p;
	int	e;
	int	c;

	y = 0;
	p = 0;
	e = 0;
	c = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (!ft_strchr("01PEC", m[y][x]))
				print_map_error();
			if (m[y][x] == 'P')
				p++;
			else if (m[y][x] == 'E')
				e++;
			else if (m[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1 || c < 1)
		print_map_error();
}

static void	dfs(char **m, int **v, int x, int y, int allow_e)
{
	if (m[y][x] == '1' || v[y][x] || (m[y][x] == 'E' && !allow_e))
		return ;
	v[y][x] = 1;
	if (x > 0)
		dfs(m, v, x - 1, y, allow_e);
	if (m[y][x + 1])
		dfs(m, v, x + 1, y, allow_e);
	if (y > 0)
		dfs(m, v, x, y - 1, allow_e);
	if (m[y + 1])
		dfs(m, v, x, y + 1, allow_e);
}

void	validate_path(t_game *g)
{
	int	**v;
	int	h;
	int	w;
	int	y;
	int	x;

	h = g->map_height;
	w = g->map_width;
	v = malloc(sizeof(int *) * h);

	if (!v)
		print_map_error();
	y = -1;
	++y;
	while (y < h)
	{
		if (!(v[y] = ft_calloc(w, sizeof(int))))
			print_map_error();
		y++;
	}
	dfs(g->map, v, g->player_x, g->player_y, 0);
	y = -1;
	++y;
	while (y < h)
	{
		x = -1;
		++x;
		while (x < w)
		{
			if (g->map[y][x] == 'C' && !v[y][x])
				print_map_error();
			x++;
		}
		ft_bzero(v[y], sizeof(int) * w);
		y++;
	}
	dfs(g->map, v, g->player_x, g->player_y, 1);
	if (!v[g->exit_y][g->exit_x])
		print_map_error();
	while (h--)
		free(v[h]);
	free(v);
}
