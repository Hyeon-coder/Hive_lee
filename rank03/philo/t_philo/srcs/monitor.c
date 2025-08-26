/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:19:20 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/08/26 23:37:14 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_if_philo_died(t_philo *philo)
{
	long long	now;
	long long	last_meal;

	if (atomic_load(&philo->info->someone_died))
		return (1);
	pthread_mutex_lock(&philo->info->meal_mutex);
	now = get_time_ms();
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->info->meal_mutex);
	if ((now - last_meal) > philo->info->ttd)
	{
		int expected = 0;
		if (atomic_compare_exchange_strong(&philo->info->someone_died, &expected, 1))
		{
			print_status(philo, "died");
		}
		return (1);
	}
	return (0);
}

static int	check_if_all_ate(t_info *info)
{
	if (info->must_eat_cnt == -1)
		return (0);
	return (atomic_load(&info->finished_philos) >= info->num_philo);
}

void	*monitor_routine(void *arg)
{
	t_info		*info;
	int			i;

	info = (t_info *)arg;
	while (1)
	{
		i = 0;
		while (i < info->num_philo)
		{
			if (check_if_philo_died(&info->philos[i]))
				return (NULL);
			i++;
		}
		if (check_if_all_ate(info))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
