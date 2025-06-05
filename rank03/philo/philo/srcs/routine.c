/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:57:20 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 03:03:38 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ───────────────────────── 내부 헬퍼 ────────────────────────────────────── */

/*
** 포크 두 개를 집는 공통 코드
**  - 짝수 철학자 : 왼쪽 → 오른쪽
**  - 홀수 철학자 : 오른쪽 → 왼쪽   (dead-lock 예방)
*/
static void	pickup_forks(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

    pthread_mutex_lock(&p->rules->mt_waiter);
	if (p->id % 2 == 0)
	{
		first = p->fork_left;
		second = p->fork_right;
	}
	else
	{
		first = p->fork_right;
		second = p->fork_left;
	}
	pthread_mutex_lock(first);
	safe_print(p, MSG_FORK);
	/* single philo 예외: 두 포인터가 같으면 바로 return (monitor가 죽음 감지) */
	if (first == second)
    {
        pthread_mutex_unlock(&p->rules->mt_waiter);
		return ;
    }
	pthread_mutex_lock(second);
	safe_print(p, MSG_FORK);
}

/* 포크 두 개 내려놓기 (순서 무관) */
static void	putdown_forks(t_philo *p)
{
	pthread_mutex_unlock(p->fork_left);
	/* 양 손이 같은 mutex(=philo 1명)인 경우 중복 unlock 방지 */
	if (p->fork_left != p->fork_right)
		pthread_mutex_unlock(p->fork_right);
    pthread_mutex_unlock(&p->rules->mt_waiter);
}

/* ───────────────────────── 공개 함수 구현 ──────────────────────────────── */

/* 먹기 */
void	philo_eat(t_philo *p)
{
	t_rules	*rules;

	rules = p->rules;
	if (rules->finished)
		return ;
	pickup_forks(p);
	/* single philosopher: 두 번째 포크를 얻지 못해 먹을 수 없음 → 바로 반환 */
	if (p->fork_left == p->fork_right)
		return ;
	pthread_mutex_lock(&rules->mt_finish);
	p->last_meal = timestamp_ms();
	pthread_mutex_unlock(&rules->mt_finish);
	safe_print(p, MSG_EAT);
	precise_sleep(rules->time_eat, rules);
	p->meals_eaten++;
	putdown_forks(p);
}

/* 자기 */
void	philo_sleep(t_philo *p)
{
	if (p->rules->finished)
		return ;
	safe_print(p, MSG_SLEEP);
	precise_sleep(p->rules->time_sleep, p->rules);
}

/* routine.c ─ think 단계 */
void philo_think(t_philo *p)
{
	t_rules     *r;
	long long   margin;

    r = p->rules;
	safe_print(p, MSG_THINK);
	if (r->nbr_philo % 2 == 0)
	{
		margin = r->time_die - (r->time_eat + r->time_sleep) - SAFETY_MS;
		if (margin > 0)
			precise_sleep(margin / 4, r);   /* 최대 (margin-1) / 2  ms */
		else
			usleep(100);                    /* 매번 0.1 ms만 휴지 */
	}
	else if (r->time_die > r->time_eat * 2 + r->time_sleep)
		precise_sleep(r->time_eat, r);      /* 1사이클 지연으로 교대 보장 */
	else
		usleep(100);
}


/* 철학자 스레드 메인 루프 */
void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;

	/* ────── ① 단 한 명만 있을 때 : 기존 로직 유지 ────── */
	if (p->rules->nbr_philo == 1)
	{
		pthread_mutex_lock(p->fork_left);
		safe_print(p, MSG_FORK);
		precise_sleep(p->rules->time_die, p->rules);
		pthread_mutex_unlock(p->fork_left);
		return (NULL);
	}

	/* ────── ② 교대 간격 확보 : 홀수 ID만 time_eat/2 만큼 지연 ────── */
	if (p->id % 2)
		precise_sleep(p->rules->time_eat / 2, p->rules);  /* 100 ms 지연 (eat = 200) */

	/* ────── ③ 메인 루프 ────── */
	while (!p->rules->finished)
	{
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}
