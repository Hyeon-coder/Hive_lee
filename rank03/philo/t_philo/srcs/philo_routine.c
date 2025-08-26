/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:19:03 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/08/27 00:11:21 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_forks(t_philo *philo)
{
	t_mutex	*first_fork;
	t_mutex	*second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	print_status(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	t_info	*info;
	int		current_eat_count;

	info = philo->info;
	pthread_mutex_lock(&info->meal_mutex);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&info->meal_mutex);
	print_status(philo, "is eating");
	my_usleep(info->tte, info);
	current_eat_count = atomic_fetch_add(&philo->eat_cnt, 1) + 1;
	if (info->must_eat_cnt != -1 && current_eat_count == info->must_eat_cnt)
	{
		atomic_fetch_add(&info->finished_philos, 1);
	}
}

static void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		my_usleep(info->tte / 2, info);
	while (!simulation_finished(info))
	{
		take_forks(philo);
		if (simulation_finished(info))
		{
			put_forks(philo);
			break ;
		}
		eat(philo);
		put_forks(philo);
		if (simulation_finished(info))
			break ;
		print_status(philo, "is sleeping");
		my_usleep(info->tts, info);
		if (simulation_finished(info))
			break ;
		print_status(philo, "is thinking");
	}
	return (NULL);
}
