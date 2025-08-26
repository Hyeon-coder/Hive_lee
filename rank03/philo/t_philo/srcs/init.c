/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:42:38 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/08/26 23:36:53 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	info->num_philo = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat_cnt = ft_atoi(av[5]);
	else
		info->must_eat_cnt = -1;
	if (info->num_philo < 1 || info->ttd < 0 || info->tte < 0 || info->tts < 0)
		return (1);
	if (info->must_eat_cnt == 0)
		return (1);
	atomic_init(&info->finished_philos, 0);
	atomic_init(&info->someone_died, 0);
	info->forks = malloc(sizeof(t_mutex) * info->num_philo);
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	if (!info->forks || !info->philos)
		return (1);
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->meal_mutex, NULL) != 0)
		return (1);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].id = i + 1;
		atomic_init(&info->philos[i].eat_cnt, 0);
		info->philos[i].last_meal = 0;
		info->philos[i].left_fork = &info->forks[i];
		info->philos[i].right_fork = &info->forks[(i + 1) % info->num_philo];
		info->philos[i].info = info;
		i++;
	}
	return (0);
}
