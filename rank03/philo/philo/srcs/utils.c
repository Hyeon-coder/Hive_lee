/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:56:32 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 02:14:06 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* ───────────────────────── 타임스탬프 ───────────────────────────────────── */
/*
** gettimeofday() 로 현재 시각을 밀리초 단위 long long 값으로 반환
*/
long long	timestamp_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL);
}

/* ───────────────────────── 정밀 슬립 ────────────────────────────────────── */
/*
** usleep() 은 10ms 단위로 깰 수 있어 부정확하므로
** 0.5ms 간격 폴링으로 목표 시간까지 대기
*/
void	precise_sleep(long long duration, t_rules *rules)
{
	long long	start;

	start = timestamp_ms();
	while (!rules->finished)
	{
		if (timestamp_ms() - start >= duration)
			break ;
		usleep(100);
	}
}

/* ───────────────────────── atoi (overflow 체크) ────────────────────────── */
/*
**  - 허용 문자는 '0'~'9'만 (parse_args 에서 이미 숫자 여부 검증)
**  - 32비트 int 범위를 넘기면 -1 반환해 오류 전파
*/
int	ft_atoi(const char *str)
{
	long long	num;

	if (!str || !*str)
		return (-1);
	num = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		num = num * 10 + (*str - '0');
		if (num > 2147483647)
			return (-1);
		str++;
	}
	return ((int)num);
}

/* ───────────────────────── 스레드 안전 출력 ─────────────────────────────── */
/*
**  - 로그 포맷: "<ms> <philo_id> <MSG>"
**  - rules->finished 가 세트되면 추가 출력 차단
*/
void	safe_print(t_philo *philo, const char *msg)
{
	t_rules	*rules;
	long long	now;

	rules = philo->rules;
	pthread_mutex_lock(&rules->mt_print);
	if (!rules->finished || strcmp(msg, MSG_DIED) == 0)
	{
		now = timestamp_ms() - rules->start_ts;
		printf("%lld %d %s\n", now, philo->id, msg);
	}
	pthread_mutex_unlock(&rules->mt_print);
}
