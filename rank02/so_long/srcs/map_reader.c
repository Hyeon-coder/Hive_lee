#include "../includes/so_long.h"

static int	get_dimensions(char *filename, int *width, int *height)
{
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*height = 1;
	*width = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	*width = ft_strlen(line);
	if (line[*width - 1] == '\n')
		(*width)--;
	last_line = line;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(last_line);
		last_line = line;
		(*height)++;
	}
	if (last_line[ft_strlen(last_line) - 1] == '\n')
	{
		free(last_line);
		close(fd);
		return (0);
	}
	free(last_line);
	close(fd);
	return (*width > 0 && *height > 0);
}

static void	cleanup_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

char	**read_map(char *filename, int *width, int *height)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;

	if (!get_dimensions(filename, width, height))
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (*height + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < *height && (line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	if (i < *height)
	{
		cleanup_map(map, i);
		return (NULL);
	}
	return (map);
}

void	free_map(char **map, int height)
{
	cleanup_map(map, height);
} 