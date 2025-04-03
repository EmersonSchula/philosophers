/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:39:41 by eschula           #+#    #+#             */
/*   Updated: 2025/03/12 16:27:49 by eschula          ###   ########.fr       */
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
				return (handle_error(E_INVALID_ARG));
			j++;
		}
		i++;
	}
	return (false);
}