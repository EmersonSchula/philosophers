/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:12:45 by eschula           #+#    #+#             */
/*   Updated: 2025/04/12 13:52:04 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "ft_malloc.h"
# include "ft_mutex.h"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_bool
{
	false,
	true
}					t_bool;

typedef enum e_status
{
	S_SLEEPING,
	S_THINKING,
	S_EATING,
	S_FORK,
	S_DEAD
}					t_status;

typedef enum e_error
{
	E_SUCCESS,
	E_FEW_ARGS,
	E_MANY_ARGS,
	E_INVALID_ARGS,
	E_MUTEX_FAILED,
	E_MALLOC_FAILED,
	E_THREAD_FAILED,
	E_INVALID_PHIL_NUM,
	
}					t_error;

typedef struct	s_thread
{
	pthread_t		thread;
	void			*(*fun)(void *);
	void			*args;
}					t_thread;

typedef struct s_utils_mutex
{
	pthread_mutex_t	philo_dead;
	pthread_mutex_t	meals;
	pthread_mutex_t	print;
}					t_utils_mutex;


typedef struct	s_forks
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}					t_forks;

typedef struct	s_philo
{
	size_t			id;
	size_t			meals;
	size_t			last_meal;
	t_thread		thread;
	t_forks			forks;
}					t_philo;

typedef struct s_rules
{
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			think_time;
	size_t			num_of_philosophers;
	size_t			num_of_meals;
	t_philo			*philo;
	t_bool			philo_dead;
	t_bool			finish;
}					t_rules;

// TIME
size_t				ft_get_time(void);
void				ft_msleep(long long ms);

// VALIDATE
t_bool				ft_all_eaten(void);
t_bool				check_philo_dead(void);
t_bool				ft_validate_args(int ac, char *av[]);

// UTILS
t_utils_mutex		*get_mutex(void);
t_rules				*get_rules(void);
t_bool				handle_error(t_error error);
void				print_status(t_philo philo, t_status status);

// LIBS
t_bool				ft_isdigit(int c);
size_t				ft_atost(const char *nptr);
size_t				ft_strlen(const char *str);

// INIT
t_bool				init_philosophers(t_rules *rules);
t_bool				init_rules(int ac, char *av[]);
t_bool				init_utils_mutex(t_utils_mutex *mtx);

// TASK
void				*philo_task(void *args);

// THREAD
void				thread_build(t_thread *thread, t_philo *philo);


#endif