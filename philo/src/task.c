/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:13:47 by eschula           #+#    #+#             */
/*   Updated: 2025/04/12 12:57:20 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void philo_take_fork(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        ft_mutex_lock(philo->forks.right);
        print_status(*philo, S_FORK);
        ft_mutex_lock(philo->forks.left);
        print_status(*philo, S_FORK);
    }
    else
    {
        ft_mutex_lock(philo->forks.left);
        print_status(*philo, S_FORK);
        ft_mutex_lock(philo->forks.right);
        print_status(*philo, S_FORK);
    }
}

void    *philo_task(void *args)
{
    t_philo *philo;

    philo = (t_philo *)args;
    if (philo->id % 2 == 0)
        ft_msleep(1);
    while (!check_philo_dead())
    {
        if (ft_all_eaten())
            break;
        philo_take_fork(philo);
    }
    return (NULL);
}