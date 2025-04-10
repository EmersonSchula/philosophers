/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:06:32 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 02:28:31 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "string.h"

void    thread_build(t_thread *thread, t_philo *philo)
{
    thread->fun = &philo_task;
    thread->args = philo;
}