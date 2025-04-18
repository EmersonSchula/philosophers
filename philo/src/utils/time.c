/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:30:07 by eschula           #+#    #+#             */
/*   Updated: 2025/04/14 14:58:19 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	ft_get_time(void)
{
	static size_t	start_time;

	if (!start_time)
	{
		start_time = get_now_time();
		return (0);
	}
	return (get_now_time() - start_time);
}

void	ft_msleep(long long ms)
{
	if (ms < 0)
		ms = 0;
	usleep(ms * 1000);
}
