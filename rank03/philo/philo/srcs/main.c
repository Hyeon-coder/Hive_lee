/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:52:53 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 01:37:32 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_table		table;
	pthread_t	monitor;
	int			i;

	/* ────── 1) 인자 파싱 ─────────────────────────────────────────── */
	if (parse_args(ac, av, &table.rules))
		return (error_exit("Error: bad arguments\n"));

	/* ────── 2) 테이블 초기화 ─────────────────────────────────────── */
	if (init_table(&table))
		return (error_exit("Error: init failed\n"));

	/* 시뮬레이션 시작 타임스탬프 저장 */
	table.rules.start_ts = timestamp_ms();

	/* ────── 3) 스레드 생성 ───────────────────────────────────────── */
	i = 0;
	while (i < table.rules.nbr_philo)
	{
		if (pthread_create(&table.philos[i].thread_id, NULL,
				philo_routine, &table.philos[i]))
			return (error_exit("Error: pthread_create (philo)\n"));
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, &table))
		return (error_exit("Error: pthread_create (monitor)\n"));

	/* ────── 4) join & 종료 대기 ──────────────────────────────────── */
	i = 0;
	while (i < table.rules.nbr_philo)
	{
		pthread_join(table.philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(monitor, NULL);

	/* ────── 5) 자원 해제 ─────────────────────────────────────────── */
	clean_table(&table);
	return (0);
}
