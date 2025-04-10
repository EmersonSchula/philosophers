/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:17 by eschula           #+#    #+#             */
/*   Updated: 2025/04/08 17:30:20 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex.h"

static t_mutex *get_mutex(void)
{
    static t_mutex mutex;
    
    return (&mutex);
}

int    ft_mutex_init(pthread_mutex_t *mutex)
{
    t_mutex *mtx;

    mtx = get_mutex();
    

    
    return (0);
}
    