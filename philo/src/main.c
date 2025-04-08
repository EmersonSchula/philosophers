/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:37:22 by eschula           #+#    #+#             */
/*   Updated: 2025/04/07 19:33:27 by eschula          ###   ########.fr       */
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
	return (0);
}