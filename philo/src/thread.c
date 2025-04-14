/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:06:32 by eschula           #+#    #+#             */
/*   Updated: 2025/04/12 19:51:14 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "string.h"

void    thread_build(t_thread *thread, t_philo *philo)
{
	thread->fun = &philo_task;
	thread->args = philo;
}

t_bool	init_thread(t_thread *thread)
{
	if (pthread_create(&thread->thread, NULL, thread->fun, thread->args))
		return (true);
	return (false);
}

void	*solo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	print_status(*philo, S_FORK);
	while (!check_philo_dead())
		ft_msleep(get_rules()->die_time / 2);
	return (NULL);
}