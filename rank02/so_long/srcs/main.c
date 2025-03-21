/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:11:48 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/19 17:25:45 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	check_map_size_line - Check map size (max_width : 3840 / max_height : 2160)
							and check the new line
	(check_map_size_line - 맵의 사이즈를 체크한다 (max_width : 3840 / max_height : 2160))
							그리고 줄바꿈을 확인 한다.
*/
static void	check_map_size_line(t_game *game)
{
	int	last_row;
	int	last_char_index;

	if (game->width > game->max_width || game->height > game->max_height)
	{
		ft_putstr_fd("Error: Map size exceeds maximum allowed size.\n", 2);
		free_map(game->map, game->height);
		exit(1);
	}
	last_row = game->height - 1;
	if (game->map[last_row])
	{
		last_char_index = ft_strlen(game->map[last_row]) - 1;
		if (game->map[last_row][last_char_index] == '\n')
		{
			ft_putstr_fd("Error: contains an extra newline at the end.\n", 2);
			free_map(game->map, game->height);
			exit(1);
		}
	}
}

/*
	load_images - Loads all necessary images for the game.
	(load_images - 게임에 필요한 모든 이미지를 로드합니다.)
*/
void	load_images(t_game *game, int *img_w, int *img_h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
									"./images/wall.xpm", img_w, img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
									"./images/chara.xpm", img_w, img_h);
	game->img_collectible_before = mlx_xpm_file_to_image(game->mlx, \
									"./images/chest.xpm", img_w, img_h);
	game->img_collectible_after = mlx_xpm_file_to_image(game->mlx, \
									"./images/chest_open.xpm", img_w, img_h);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx, \
									"./images/rune.xpm", img_w, img_h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, \
									"./images/rune_light.xpm", img_w, img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
									"./images/land.xpm", img_w, img_h);
	if (!game->img_wall || !game->img_player || !game->img_collectible_before
		|| !game->img_collectible_after || !game->img_exit_close
		|| !game->img_exit_open || !game->img_floor)
	{
		ft_putstr_fd("Error: Failed to load images\n", 2);
		exit(1);
	}
}

/*
	init_mlx_window - Sets up the MLX window for rendering.
	(init_mlx_window - MLX 창을 설정하여 렌더링을 준비합니다.)
*/
static void	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MiniLibX\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * game->tile_size, \
	game->height * game->tile_size, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		exit(1);
	}
}

/*
	init_game - Initializes game variables and settings.
	(init_game - 게임 변수와 설정을 초기화합니다.)
*/
static void	init_game(t_game *game, char *map_file)
{
	int	img_w;
	int	img_h;

	game->map = read_map(map_file, &game->width, &game->height);
	game->tile_size = 64;
	game->max_width = (3840 / game->tile_size);
	game->max_height = (2160 / game->tile_size) - 1;
	if (!game->map || !validate_map(game))
	{
		free_map(game->map, game->height);
		exit(1);
	}
	check_map_size_line(game);
	init_mlx_window(game);
	load_images(game, &img_w, &img_h);
}

/*
	main - Entry point of the game.
	(main - 게임의 진입점입니다.)
*/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Please provide a map file (.ber)\n", 2);
		return (1);
	}
	init_game(&game, argv[1]);
	render_map(&game);
	game.moves = 0;
	write(1, "moves : ", 8);
	ft_putnbr_fd(game.moves, 1);
	write(1, "\n", 1);
	mlx_expose_hook(game.win, handle_expose, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
