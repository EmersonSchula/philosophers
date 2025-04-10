/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:39:41 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 02:23:24 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_validate_args(int ac, char *av[])
{
	int	i;
	int	j;

	if (ac < 5)
		return (handle_error(E_FEW_ARGS));
	if (ac > 6)
		return (handle_error(E_MANY_ARGS));
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (handle_error(E_INVALID_ARGS));
			j++;
		}
		i++;
	}
	return (false);
}

t_bool	check_philo_dead(void)
{
	ft_mutex_lock(&get_mutex()->philo_dead);
	if (get_rules()->philo_dead)
	{
		ft_mutex_unlock(&get_mutex()->philo_dead);
		return (true);
	}
	ft_mutex_unlock(&get_mutex()->philo_dead);
	return (false);
}

t_bool	ft_all_eaten(void)
{
	ft_mutex_lock(&get_mutex()->meals);
	if (get_rules()->finish)
	{
		ft_mutex_unlock(&get_mutex()->meals);
		return (true);
	}
	ft_mutex_unlock(&get_mutex()->meals);	
	return (false);
}