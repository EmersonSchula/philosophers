/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:11 by eschula           #+#    #+#             */
/*   Updated: 2025/04/10 02:07:14 by eschula          ###   ########.fr       */
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