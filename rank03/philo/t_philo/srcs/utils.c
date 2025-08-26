/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:19:36 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/08/27 00:14:42 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	my_usleep(long long ms, t_info *info)
{
	long long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < ms)
	{
		if (simulation_finished(info))
			break ;
		usleep(500);
	}
}

int	simulation_finished(t_info *info)
{
	int	died;
	int	finished;

	if (!info)
		return (0);
	died = atomic_load(&info->someone_died);
	finished = (info->must_eat_cnt != -1 
			&& atomic_load(&info->finished_philos) >= info->num_philo);
	return (died || finished);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while ('0' <= *str && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}
