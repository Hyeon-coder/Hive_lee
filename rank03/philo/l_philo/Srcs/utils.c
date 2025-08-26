/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:47:59 by tripham           #+#    #+#             */
/*   Updated: 2025/05/09 17:35:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t  get_time(void)
{
    struct timeval  time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int  is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->mt_terminate);
    if (philo->terminate && *philo->terminate == 1)
    {
        pthread_mutex_unlock(philo->mt_terminate);
        return (1);
    }
    pthread_mutex_unlock(philo->mt_terminate);
    return (0);
}
void    ft_usleep(t_philo *philo, size_t ms)
{
    size_t  start;

    start = get_time();
    while ((get_time() - start) < ms)
    {
        if (philo)
        {
            if (is_dead(philo))
            {
                break ;
            }
        }
        usleep(1000);
    }
}

void    print_end_program(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&data->mt_print);
    if (data->must_eat != -1
        && data->philo_cnt_all == data->philo_cnt)
        printf("Every philosopher ate %d times\n", data->must_eat);
    else
        printf("%zu %d died\n",
            get_time() - philo->start_ms, philo->id + 1);
    pthread_mutex_unlock(&data->mt_print);
}
