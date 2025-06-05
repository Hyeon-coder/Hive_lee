/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:47:23 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/05 02:43:40 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define MSG_FORK	"has taken a fork"
# define MSG_EAT	"is eating"
# define MSG_SLEEP	"is sleeping"
# define MSG_THINK	"is thinking"
# define MSG_DIED	"died"
# define SAFETY_MS	1

typedef struct s_rules
{
	int				nbr_philo;		/* 철학자(=포크) 수            */
	long long			time_die;		/* 굶어죽는 한계 시간          */
	long long			time_eat;		/* 식사 소요 시간              */
	long long			time_sleep;		/* 수면 소요 시간              */
	int				must_eat;		/* 최소 식사 횟수(옵션)        */
	long long			start_ts;		/* 시뮬 시작 타임스탬프        */
	int				finished;		/* 종료 플래그                 */

	/* 글로벌 보호용 뮤텍스 */
	pthread_mutex_t	mt_print;		/* 로그 출력 직렬화           */
	pthread_mutex_t	mt_finish;		/* finished 보호              */
	pthread_mutex_t mt_waiter;  /* N-1 로 제한하는 세마포어 역할 */
}	t_rules;

/* ───────────── 철학자 개체 ──────────────────────────────────────────────── */
typedef struct s_philo
{
	int				id;				/* 1 ~ N 철학자 번호           */
	int				meals_eaten;	/* 현재까지 먹은 횟수          */
	long long			last_meal;		/* 마지막으로 먹기 시작 시각   */

	pthread_mutex_t	*fork_left;		/* 왼쪽 포크 */
	pthread_mutex_t	*fork_right;	/* 오른쪽 포크 */

	pthread_t		thread_id;		/* 해당 철학자 스레드 ID       */
	t_rules			*rules;			/* 전역 규칙 포인터           */
}	t_philo;

/* ───────────── 테이블(시뮬 전체 데이터) ─────────────────────────────────── */
typedef struct s_table
{
	t_rules			rules;
	t_philo			*philos;		/* 크기: rules.nbr_philo       */
	pthread_mutex_t	*forks;			/* 크기: rules.nbr_philo       */
}	t_table;

/* init & 파싱 */
int		parse_args(int ac, char **av, t_rules *rules);
int		init_table(t_table *table);

/* 유틸리티 */
long long	timestamp_ms(void);
void	precise_sleep(long long duration, t_rules *rules);
int		ft_atoi(const char *str);
void	safe_print(t_philo *philo, const char *msg);

/* 스레드 루틴 */
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

/* 행동 helpers (선택 구현) */
void	philo_eat(t_philo *p);
void	philo_sleep(t_philo *p);
void	philo_think(t_philo *p);

/* 정리 */
void	clean_table(t_table *table);
int		error_exit(const char *msg);

#endif /* PHILO_H */
