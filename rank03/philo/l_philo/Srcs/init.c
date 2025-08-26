/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:17:13 by trietpham         #+#    #+#             */
/*   Updated: 2025/05/09 18:09:10 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	get_val(t_data *data, int i)
{
	data->philos[i]->id = i;
	data->philos[i]->terminate = &data->terminate;
	data->philos[i]->philo_cnt_all = &data->philo_cnt_all;
	data->philos[i]->must_eat = data->must_eat;
	data->philos[i]->philo_cnt = data->philo_cnt;
	data->philos[i]->start_ms = data->start_ms;
	data->philos[i]->die = data->die;
	data->philos[i]->sleep = data->sleep;
	data->philos[i]->eat = data->eat;
	data->philos[i]->mt_lock = &data->mt_lock;
	data->philos[i]->mt_print = &data->mt_print;
	data->philos[i]->mt_terminate = &data->mt_terminate;
	data->philos[i]->left_fork = &data->mt_forks[i];
	data->philos[i]->right_fork = &data->mt_forks[(i + 1) % data->philo_cnt];
}

static int	ft_mem_alloc(t_data *data)
{
	data->mt_forks = (t_mutex *)ft_calloc(data->philo_cnt + 1,
			sizeof(t_mutex));
	if (!data->mt_forks)
		return (0);
	data->philos = (t_philo **)ft_calloc(data->philo_cnt + 1,
			sizeof(t_philo *));
	if (!data->philos)
		return (0);
	return (1);
}
/** 
 * All mutex in the philo is inited in this function
 * 1. mutex_lock_meal
 * 2. mutex_print
 * 3. mutex_terminate
*/
static int	mt_init(t_data *data)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&data->mt_lock, NULL))
		return (error_return("Init mutex faild\n", 0));
	if (pthread_mutex_init(&data->mt_print, NULL))
		return (error_return("Init mutex faild\n", 0));
	if (pthread_mutex_init(&data->mt_terminate, NULL))
		return (error_return("Init mutex faild\n", 0));
	while (i < data->philo_cnt)
	{
		if (pthread_mutex_init(&data->mt_forks[i], NULL))
			return (error_return("Init mutex faild\n", 0));
		i++;
	}
	return (1);
}

static int	philo_init(t_data *data)
{
	size_t	start_ms;
	int		i;

	i = 0;
	start_ms = get_time() + 3000;
	while (i < data->philo_cnt)
	{
		data->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!data->philos[i])
			return (error_return("Malloc fail for t_philo\n", 0));
		memset(data->philos[i], 0, sizeof(t_philo));
		get_val(data, i);
		data->start_ms = start_ms; // double check, should it move to out of the loop?
		data->philos[i]->start_ms = start_ms;
		data->philos[i]->last_meal_ms = start_ms;
		i++;
	}
	return (1);
}

int ft_init(int ac, char **av, t_data *data)
{
	data->ac = ac;
	data->av = av;
	data->philo_cnt = (int) ft_atol(av[1]);
	data->die = ft_atol(av[2]);
	data->eat = ft_atol(av[3]);
	data->sleep = ft_atol(av[4]);
	if (ac == 6)
		data->must_eat = ft_atol(av[5]);
	else
		data->must_eat = -1;
	if (!ft_mem_alloc(data))
		return (0);
	if (!mt_init(data))
		return (0);
	if (!philo_init(data))
		return (0);
	return (1);
}
