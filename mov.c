/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:56:41 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/13 20:56:41 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int keys(int keycode, t_cub3d *cub3d)
{
    if (keycode == W)
        cub3d->w = 1;
    if (keycode == A)
        cub3d->a = 1;
    if (keycode == S)
        cub3d->s = 1;
    if (keycode == D)
        cub3d->d = 1;
    if (keycode == LEFT)
        cub3d->t_left = 1;
    if (keycode == RIGHT)
        cub3d->t_right = 1;
    return (0);
}

