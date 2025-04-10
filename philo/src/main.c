/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:37:22 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 15:56:02 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (ft_validate_args(argc, argv))
		return (1);
	if (init_rules(argc, argv))
		return (1);
	if (init_philosophers(get_rules()))
		return (1);
	if (init_utils_mutex(get_mutex()))
		return (1);
	if (start_philo_task(get_rules()))
		return (1);
	return (0);
}