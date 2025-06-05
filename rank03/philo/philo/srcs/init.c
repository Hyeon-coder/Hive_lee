/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:54:53 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 02:44:30 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* ───────────────────────── 내부 헬퍼 ────────────────────────────────────── */

/* 인자가 순수 숫자인지 검사 (0~9 외 문자 존재 시 0 반환) */
static int	is_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* 포크 배열 뮤텍스를 초기화하고, 실패 시 이미 만든 것 롤백 */
static int	init_mutex_array(pthread_mutex_t *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&arr[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&arr[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

/* ───────────────────────── 인자 파싱 ───────────────────────────────────── */

int	parse_args(int ac, char **av, t_rules *rules)
{
	if (ac != 5 && ac != 6)
		return (1);
	/* 모든 인자가 숫자인지 확인 */
	for (int i = 1; i < ac; i++)
		if (!is_number(av[i]))
			return (1);
	rules->nbr_philo = ft_atoi(av[1]);
	rules->time_die = ft_atoi(av[2]);
	rules->time_eat = ft_atoi(av[3]);
	rules->time_sleep = ft_atoi(av[4]);
	rules->must_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
	/* 값이 0 이하이면 오류 */
	if (rules->nbr_philo <= 0 || rules->time_die <= 0 || rules->time_eat <= 0
		|| rules->time_sleep <= 0 || (ac == 6 && rules->must_eat <= 0))
		return (1);
	rules->finished = 0;
	return (0);
}

/* ───────────────────────── 테이블 초기화 ──────────────────────────────── */

int	init_table(t_table *table)
{
	const int	n = table->rules.nbr_philo;
	int			i;

	table->forks = malloc(sizeof(pthread_mutex_t) * n);
	table->philos = malloc(sizeof(t_philo) * n);
	if (!table->forks || !table->philos)
		return (1);
	if (init_mutex_array(table->forks, n))
		return (1);
	if (pthread_mutex_init(&table->rules.mt_print, NULL)
		|| pthread_mutex_init(&table->rules.mt_finish, NULL)
		|| pthread_mutex_init(&table->rules.mt_waiter, NULL))
		return (1);
	i = 0;
	while (i < n)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0; /* start_ts 기록 후 갱신 */
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right = &table->forks[(i + 1) % n];
		table->philos[i].rules = &table->rules;
		i++;
	}
	return (0);
}
