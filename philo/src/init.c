/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:23:38 by eschula           #+#    #+#             */
/*   Updated: 2025/04/07 19:53:53 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
