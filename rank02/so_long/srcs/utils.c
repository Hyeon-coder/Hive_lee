/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:56 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/06 07:20:50 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	ft_putstr_fd - Writes a string to the given file descriptor.
	(ft_putstr_fd - 문자열을 지정된 파일 디스크립터에 출력합니다.)
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

/*
	ft_putnbr_fd - Writes an integer to the given file descriptor.
	(ft_putnbr_fd - 정수를 지정된 파일 디스크립터에 출력합니다.)
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 10)
	{
		temp = n + '0';
		write(fd, &temp, 1);
	}
}

/*
	free_map - Frees allocated memory for the map structure.
	(free_map - 맵 구조체에 할당된 메모리를 해제합니다.)
*/
void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
