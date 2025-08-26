/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:17:50 by trietpham         #+#    #+#             */
/*   Updated: 2025/05/09 18:04:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_philo
{
	int					id;
	int					*terminate;
	int					*philo_cnt_all;
	int					meal_eaten;
	int					must_eat;
	int					philo_cnt;
	size_t				last_meal_ms;
	size_t				start_ms;
	size_t				die;
	size_t				sleep;
	size_t				eat;
	t_thread			pthread;
	t_mutex				*left_fork;
	t_mutex				*right_fork;
	t_mutex				*mt_lock;
	t_mutex				*mt_print;
	t_mutex				*mt_terminate;
}	t_philo;

typedef struct s_data
{
	int			ac;
	char		**av;
	int			terminate;
	int			philo_cnt;
	int			philo_cnt_all;
	int			must_eat;
	size_t		die;
	size_t		eat;
	size_t		sleep;
	size_t		start_ms;
	t_mutex		mt_lock;
	t_mutex		mt_print;
	t_mutex		mt_terminate;
	t_mutex		*mt_forks;
	t_philo		**philos;
}	t_data;

int		arg_check(int ac, char **av);

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *s);

int		error_return(char *str, int val);
int		ft_init(int ac, char **av, t_data *data);

size_t	get_time(void);
void	ft_usleep(t_philo *philo, size_t ms);
int		is_dead(t_philo *philo);
void	error_mess(char *str);
int		philo_mess(t_philo *philo, char *str);
void	error_mess_exit(char *str, int exitcode);
void	*routine(void *philo_arg);
int		ft_simu(t_data *data);
void	print_end_program(t_data *data, t_philo *philo);
int		destroy(t_data *data);

#endif