/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:07:32 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 01:07:33 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** 철학자 i가 굶어 죽었는지 검사.
**  last_meal==0이면 아직 한 번도 먹지 않은 상태 → 시뮬 시작 시각을 기준으로 계산.
*/
static int	check_dead(t_table *t, int i, long long now)
{
	long long	last;

	pthread_mutex_lock(&t->rules.mt_finish);
	last = t->philos[i].last_meal ? t->philos[i].last_meal : t->rules.start_ts;
	if (!t->rules.finished && now - last >= t->rules.time_die)
	{
		t->rules.finished = 1;
		pthread_mutex_unlock(&t->rules.mt_finish);   /* ⚠️ deadlock 방지: 먼저 해제 */
		safe_print(&t->philos[i], MSG_DIED);         /* mt_print 잠글 때 교착 無   */
		return (1);
	}
	pthread_mutex_unlock(&t->rules.mt_finish);
	return (0);
}

/*
** 모든 철학자가 must_eat 회수를 채웠는지 확인.
**  - rules.must_eat == -1 (옵션 미사용) 인 경우 바로 0 반환.
*/
static int	check_full(t_table *t)
{
	int	i;
	int	finished_cnt;

	if (t->rules.must_eat == -1)
		return (0);
	finished_cnt = 0;
	pthread_mutex_lock(&t->rules.mt_finish);
	i = 0;
	while (i < t->rules.nbr_philo)
	{
		if (t->philos[i].meals_eaten >= t->rules.must_eat)
			++finished_cnt;
		i++;
	}
	if (finished_cnt == t->rules.nbr_philo)
		t->rules.finished = 1;
	pthread_mutex_unlock(&t->rules.mt_finish);
	return (t->rules.finished);
}

/*
** 모니터 스레드:
**  1) 주기적으로 각 철학자 생존 여부 확인
**  2) must_eat 옵션이 있으면 전체 식사 완료 여부 확인
**  3) 종료 조건을 만족하면 rules.finished 플래그 세트 후 리턴
*/
void	*monitor_routine(void *arg)
{
	t_table	*t;
	long long	now;
	int		i;

	t = (t_table *)arg;
	while (!t->rules.finished)
	{
		now = timestamp_ms();
		i = 0;
		while (i < t->rules.nbr_philo && !t->rules.finished)
		{
			if (check_dead(t, i, now))
				return (NULL);
			i++;
		}
		if (check_full(t))
			return (NULL);
		usleep(1000);  /* 1 ms 간격으로 폴링 → CPU 과점 방지 */
	}
	return (NULL);
}
