/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:26:19 by tripham           #+#    #+#             */
/*   Updated: 2025/05/09 17:31:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  create_thread(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_cnt)
    {
        if (pthread_create(&data->philos[i]->pthread, NULL, routine, (void *)data->philos[i]) != 0)
            return (error_return("monitor thread: create failed\n", 0));
        ++i;
    }
    return (1);
}

static int   thread_join(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_cnt)
    {
        if (pthread_join(data->philos[i]->pthread, NULL) != 0)
        {
            return (
                error_return("Thread join failed\n", 0));
        }
        i++;
    }
    return (1);
}

static int ft_monitor_condition(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_cnt)
    {
        pthread_mutex_lock(&data->mt_lock);
        if(get_time() - data->philos[i]->last_meal_ms >= data->die
        || data->philo_cnt_all >= data->philo_cnt)
        {
            pthread_mutex_lock(&data->mt_terminate);
            data->terminate = 1;
            pthread_mutex_unlock(&data->mt_terminate);
            print_end_program(data, data->philos[i]);
            pthread_mutex_unlock(&data->mt_lock);
            return (1);
        }
        i++;
        pthread_mutex_unlock(&data->mt_lock);
        usleep(300);
    }
    return (0);
}

static void ft_monitor(t_data *data)
{
    ft_usleep(NULL, data->start_ms - get_time());
    while (1)
    {
        if (ft_monitor_condition(data))
            break ;
    }
}

int ft_simu(t_data *data)
{
    if (!create_thread(data))
        return (0);
    ft_monitor(data);
    if (!thread_join(data))
        return (0);
    return (1);
}
