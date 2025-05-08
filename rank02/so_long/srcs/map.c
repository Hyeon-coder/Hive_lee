/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 05:10:36 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	append_to_buffer(t_file_buffer *f)
{
	f->tmp[f->bytes] = '\0';
	f->new_buf = malloc(f->total + f->bytes + 1);
	if (!f->new_buf)
	{
		free(f->buffer);
		error_exit("Error\nmalloc failed");
	}
	ft_strlcpy(f->new_buf, f->buffer, f->total + 1);
	ft_strlcat(f->new_buf, f->tmp, f->total + f->bytes + 1);
	free(f->buffer);
	f->buffer = f->new_buf;
	f->total += f->bytes;
}

char	*read_file(const char *filename)
{
	t_file_buffer	f;

	f.fd = open(filename, O_RDONLY);
	if (f.fd < 0)
		error_exit("Error\nFailed to open map file");
	f.buffer = malloc(1);
	if (!f.buffer)
		error_exit("Error\nmalloc failed");
	f.buffer[0] = '\0';
	f.total = 0;
	f.bytes = read(f.fd, f.tmp, 1023);
	while (f.bytes > 0)
	{
		append_to_buffer(&f);
		f.bytes = read(f.fd, f.tmp, 1023);
	}
	close(f.fd);
	if (f.total == 0)
	{
		free(f.buffer);
		return (NULL);
	}
	return (f.buffer);
}

int	validate_no_empty_lines(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len == 0 || s[0] == '\n' || s[len - 1] == '\n'
		|| ft_strnstr(s, "\n\n", len))
		return (0);
	for (size_t i = 0; s[i]; ++i)
		if (s[i] == '\n' && s[i + 1] == '\0')
			return (0);
	return (1);
}

char	**read_map(const char *filename, t_game *game, t_path_ctx *ctx)
{
	char	*content;
	char	**map;
	int		i;

	content = read_file(filename);
	if (!content)
		error_exit_with_ctx("Error\nFailed to read map file", ctx);
	if (!validate_no_empty_lines(content))
		error_exit_free("Error\n", content, ctx);
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		error_exit_with_ctx("Error\nFailed to split map", ctx);
	i = 0;
	while (map[i])
		i++;
	game->map_height = i;
	game->map_width = ft_strlen(map[0]);
	game->map = map;
	ctx->map = map;
	count_player_and_coins(map, game);
	return (map);
}
