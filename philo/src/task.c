/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:13:47 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 02:01:42 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
    }
    return (NULL);
}