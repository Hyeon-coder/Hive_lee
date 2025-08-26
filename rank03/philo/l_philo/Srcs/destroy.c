/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:10:25 by tripham           #+#    #+#             */
/*   Updated: 2025/05/09 17:22:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data->mt_forks)
	{
		while (i < data->philo_cnt)
		{
			pthread_mutex_destroy(&data->mt_forks[i]);
			i++;
		}
		free(data->mt_forks);
		data->mt_forks = NULL;
	}
	pthread_mutex_destroy(&data->mt_lock);
	pthread_mutex_destroy(&data->mt_print);
	pthread_mutex_destroy(&data->mt_terminate);
	return (1);
}

static int	free_philos(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos)
	{
		while (i < data->philo_cnt)
		{
			if (!data->philos[i])
				break ;
			free(data->philos[i]);
			data->philos[i] = NULL;
			i++;
		}
		free(data->philos);
		data->philos = NULL;
	}
	return (1);
}

int	destroy(t_data *data)
{
	destroy_mutex(data);
	free_philos(data);
	return (1);
}
