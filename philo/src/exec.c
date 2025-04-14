/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:07:12 by eschula           #+#    #+#             */
/*   Updated: 2025/04/13 23:19:57 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool   is_dead(t_philo philo)
{
    ft_mutex_lock(&get_mutex()->meals);
    if (ft_get_time() - philo.last_meal > get_rules()->die_time)
    {
        ft_mutex_unlock(&get_mutex()->meals);
        print_status(philo, S_DEAD);
        ft_mutex_lock(&get_mutex()->philo_dead);
        get_rules()->philo_dead = true;
        ft_mutex_unlock(&get_mutex()->philo_dead);
        return (true);
    }
    ft_mutex_unlock(&get_mutex()->meals);
    return (false);
}

static size_t   ft_how_many_finished(void)
{
    size_t  i;
    size_t  count;

    i = 0;
    count = 0;
    while (i < get_rules()->num_of_philosophers)
    {
        ft_mutex_lock(&get_mutex()->meals);
        if (get_rules()->philo[i].meals == get_rules()->num_of_meals)
            count++;
        ft_mutex_unlock(&get_mutex()->meals);
        i++;
    }
    return (count);
}

static t_bool   all_finished(t_rules *rules)
{
    if (ft_how_many_finished() == rules->num_of_philosophers)
    {
        ft_mutex_lock(&get_mutex()->meals);
        rules->finish = true;
        ft_mutex_unlock(&get_mutex()->meals);
        return (true);        
    }
    return (false);
}

static void ft_monitor(void)
{
    t_rules *rules;
    size_t  i;

    rules = get_rules();
    while (1)
    {
        i = 0;
        while ((i < rules->num_of_philosophers))
        {
            if (is_dead(rules->philo[i]))
                return ;
            if ((all_finished(rules)))
                return ;
            i++;
        }
    }
}

t_bool  start_philo_task(t_rules *rules)
{
    t_philo *philo;
    size_t  i;

    if (rules->num_of_philosophers == 1)
    {
        philo = &rules->philo[0];
        philo->thread.fun = &solo_routine;
        if (init_thread(&philo->thread))
            return (handle_error(E_THREAD_FAILED));
    }
    else
    {
        i = 0;
        while (i < rules->num_of_philosophers)
        {
            philo = &rules->philo[i];
            if (init_thread(&philo->thread))
                return (handle_error(E_THREAD_FAILED));
            i++;
        }
    }
    ft_monitor();
    return (false);
}
