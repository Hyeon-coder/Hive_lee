/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:33:55 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/14 01:12:14 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../push_swap.h"

/*
	Converts a string to an integer. (문자열을 정수로 변환)
*/
int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		nptr++;
	}
	return ((int)(result * sign));
}

int	ft_atoi_with_free(char **args, const char *nptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		{
			write(2, "Error\n", 6);
			ft_free_args(args);
			exit(0);
		}
		nptr++;
	}
	return ((int)(result * sign));
}
