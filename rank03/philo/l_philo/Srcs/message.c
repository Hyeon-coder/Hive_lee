/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:39 by tripham           #+#    #+#             */
/*   Updated: 2025/05/08 22:00:33 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_return(char *str, int val)
{
	int len;

	len = ft_strlen(str);
	(void)!write(2, str, len);
	return (val);
}

void	error_mess_exit(char *str, int exitcode)
{
	int	len;

	len = (int) ft_strlen(str);
	(void)!write(2, str, len);
	exit(exitcode);
}

void	error_mess(char *str)
{
	int	len;

	len = ft_strlen(str);
	(void)!write(2, str, len);
}

int	philo_mess(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->mt_print);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->mt_print);
		return (1);
	}
	time = get_time() - philo->start_ms;
	printf("%zu %d %s\n", time, philo->id + 1, str);
	pthread_mutex_unlock(philo->mt_print);
	return (1);
}
