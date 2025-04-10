/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:56 by eschula           #+#    #+#             */
/*   Updated: 2025/04/09 14:11:37 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_H
# define FT_MUTEX_H

# include <pthread.h>
# include <stdlib.h>

typedef struct  s_mutex
{
    pthread_mutex_t *list[1000];
    size_t          i;
}                   t_mutex;

int    ft_mutex_init(pthread_mutex_t *mutex);

#endif