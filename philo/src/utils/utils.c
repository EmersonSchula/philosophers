/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:11 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 17:14:26 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_rules	*get_rules(void)
{
	static t_rules	rules;

	return (&rules);
}

t_utils_mutex	*get_mutex(void)
{
	static t_utils_mutex	mutex;

	return (&mutex);
}

static void	print_msg(int id, char *msg)
{
	ft_mutex_lock(&get_mutex()->print);
}

void	print_status(t_philo philo, t_status status)
{
	if (status == S_FORK)
		print_msg(philo.id, C_WHT C_BLD "has taken a fork" C_RST);
}