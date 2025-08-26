
#include "../includes/philo.h"

void	print_status(t_philo *philo, const char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->info->print_mutex);
	if (!atomic_load(&philo->info->someone_died))
	{
		timestamp = get_time_ms() - philo->info->start_time;
		printf("%lld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	print_death(t_philo *philo)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->info->print_mutex);
	timestamp = get_time_ms() - philo->info->start_time;
	printf("%lld %d died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
