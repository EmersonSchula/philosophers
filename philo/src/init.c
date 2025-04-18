/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:23:38 by eschula           #+#    #+#             */
/*   Updated: 2025/04/14 15:05:55 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	init_utils_mutex(t_utils_mutex *mtx)
{
	if (ft_mutex_init(&mtx->meals))
		return (handle_error(E_MUTEX_FAILED));
	if (ft_mutex_init(&mtx->print))
		return (handle_error(E_MUTEX_FAILED));
	if (ft_mutex_init(&mtx->philo_dead))
		return (handle_error(E_MUTEX_FAILED));
	return (false);
}

t_bool	init_rules(int ac, char *av[])
{
	t_rules	*rules;

	rules = get_rules();
	rules->philo_dead = false;
	rules->num_of_philosophers = ft_atost(av[1]);
	if (rules->num_of_philosophers < 1)
		return (handle_error(E_INVALID_PHIL_NUM));
	if (rules->num_of_philosophers > 200)
		return (handle_error(E_INVALID_PHIL_NUM));
	rules->die_time = ft_atost(av[2]);
	rules->eat_time = ft_atost(av[3]);
	rules->sleep_time = ft_atost(av[4]);
	rules->think_time = rules->die_time - rules->eat_time - rules->sleep_time;
	if (rules->think_time > 5)
		rules->think_time = 5;
	if (ac == 6)
		rules->num_of_meals = ft_atost(av[5]);
	else
		rules->num_of_meals = __SIZE_MAX__;
	rules->philo = ft_malloc(sizeof(t_philo) * rules->num_of_philosophers);
	return (false);
}

static t_bool	ft_init_forks(t_forks *forks, size_t i)
{
	static t_forks			*first_fork;
	static pthread_mutex_t	*last;

	if (i == 0)
	{
		forks->right = ft_malloc(sizeof(pthread_mutex_t));
		if (ft_mutex_init(forks->right))
			return (handle_error(E_MUTEX_FAILED));
		last = forks->right;
		first_fork = forks;
	}
	else
	{
		forks->right = ft_malloc(sizeof(pthread_mutex_t));
		if (ft_mutex_init(forks->right))
			return (handle_error(E_MUTEX_FAILED));
		forks->left = last;
		last = forks->right;
		if (i == get_rules()->num_of_philosophers - 1)
			first_fork->left = forks->right;
	}
	return (false);
}

t_bool	init_philosophers(t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < rules->num_of_philosophers)
	{
		rules->philo[i].id = i + 1;
		if (ft_init_forks(&rules->philo[i].forks, i))
			return (true);
		thread_build(&rules->philo[i].thread, &rules->philo[i]);
		i++;
	}
	return (false);
}
