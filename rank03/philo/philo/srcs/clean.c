/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:08:31 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 01:08:54 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* ───────────────────────── 에러 헬퍼 ────────────────────────────────────── */
/*
**  표준 에러로 메시지를 출력하고 1을 반환.
**  (42 MiniLibX 프로젝트 스타일에 맞춘 simple helper)
*/
int	error_exit(const char *msg)
{
	if (msg)
		fputs(msg, stderr);
	return (1);
}

/* ───────────────────────── 자원 정리 ────────────────────────────────────── */

void	clean_table(t_table *t)
{
	int	i;

	if (!t)
		return ;
	/* 포크 뮤텍스 파괴 */
	if (t->forks)
	{
		i = 0;
		while (i < t->rules.nbr_philo)
		{
			pthread_mutex_destroy(&t->forks[i]);
			i++;
		}
		free(t->forks);
	}
	/* 전역 보호용 뮤텍스 파괴 */
	pthread_mutex_destroy(&t->rules.mt_print);
        pthread_mutex_destroy(&t->rules.mt_finish);
        pthread_mutex_destroy(&t->rules.mt_waiter);
	/* 철학자 배열 해제 */
	free(t->philos);
}
