/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <eschula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:59:25 by eschula           #+#    #+#             */
/*   Updated: 2025/04/08 13:50:59 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "string.h"

void    *ft_malloc(size_ size)
{
    t_malloc    *mlc;
    void        *ptr;

    mlc = get_malloc();
    ptr = malloc(size);
    mlc->list[mlc->i] = ptr;
    mlc->i++;
    return (ptr);
}

