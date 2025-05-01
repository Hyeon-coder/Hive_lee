/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:17:39 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/23 20:23:29 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *buffer)
{
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
		return (NULL);
	return (buffer);
}

char	*ft_update_left_str(int fd, char *left)
{
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(left, '\n'))
	{
		if (!ft_read_buffer(fd, buffer))
		{
			free(buffer);
			return (left);
		}
		temp = ft_strjoin(left, buffer);
		if (left)
			free(left);
		left = temp;
		if (!left)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (left);
}

char	*ft_extract_line(char *left)
{
	char	*line;
	int		i;

	i = 0;
	if (!left || !*left)
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_trim_left_str(char *left)
{
	char	*new_left;
	int		i;
	int		j;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	new_left = malloc((ft_strlen(left) - i + 1) * sizeof(char));
	if (!new_left)
	{
		free(left);
		return (NULL);
	}
	j = 0;
	while (left[++i])
		new_left[j++] = left[i];
	new_left[j] = '\0';
	free(left);
	return (new_left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left)
	{
		left = malloc(1);
		if (!left)
			return (NULL);
		left[0] = '\0';
	}
	left = ft_update_left_str(fd, left);
	if (!left)
		return (NULL);
	line = ft_extract_line(left);
	left = ft_trim_left_str(left);
	return (line);
}
