/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:46:39 by tripham           #+#    #+#             */
/*   Updated: 2025/05/09 17:33:34 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_pick_fork(t_philo *philo)
{
    if (pthread_mutex_lock(philo->left_fork) != 0)
    {
        error_mess("Left fork: mutex_lock fail\n");
        exit (1);
    }
    philo_mess(philo, "has taken a fork");
    if (philo->philo_cnt == 1)
        return (pthread_mutex_unlock(philo->left_fork), 0);
    if (pthread_mutex_lock(philo->right_fork) != 0)
    {
        error_mess("Right fork: mutex_lock fail\n");
        exit (1);
    }
    philo_mess(philo, "has taken a fork");
    return (1);
}

static int  ft_eat(t_philo *philo)
{
    if (pthread_mutex_lock(philo->mt_lock) != 0)
        error_mess_exit("ft_eat: mutex_lock fail\n", 1);
    philo->meal_eaten++;
    philo->last_meal_ms = get_time();
    if (pthread_mutex_unlock(philo->mt_lock) != 0)
        error_mess_exit("ft_eat: mutex_unlock fail\n", 1);
    philo_mess(philo, "is eating");
    ft_usleep(philo, philo->eat);
    if (pthread_mutex_lock(philo->mt_lock) != 0)
        error_mess_exit("ft_eat: mutex_lock fail\n", 1);
    if (philo->meal_eaten == philo->must_eat)
    {
        (*philo->philo_cnt_all)++;
    }
    if (pthread_mutex_unlock(philo->mt_lock) != 0)
        error_mess_exit("ft_eat: mutex_unlock fail\n", 1);
    if (pthread_mutex_unlock(philo->left_fork) != 0)
        error_mess_exit("left_fork: mutex_unlock fail\n", 1);
    if (pthread_mutex_unlock(philo->right_fork) != 0)
        error_mess_exit("right_fork: mutex_unlock fail\n", 1);
    return (1);
}

static int  ft_sleep_think(t_philo *philo)
{
    if (!philo_mess(philo, "is sleeping"))
        return (0);
    ft_usleep(philo, philo->sleep);
    if (!philo_mess(philo, "is thinking"))
        return (0);
    return (1);
}

void    *routine(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *)philo_arg;
    ft_usleep(NULL, philo->start_ms - get_time());
    if (philo->id % 2 != 0)
        ft_usleep(philo, philo->eat / 2);
    while (1)
    {
        if (!ft_pick_fork(philo))
            break ;
        if (!ft_eat(philo))
            break ;
        if (!ft_sleep_think(philo))
            break ;
        if (is_dead(philo))
            break ;
    }
    return (NULL);
}
