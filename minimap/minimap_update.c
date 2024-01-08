/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:50 by misidori          #+#    #+#             */
/*   Updated: 2024/01/04 17:19:59 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	LEGEND:

	0 = floor
	1 = wall
	2 = egg
	D = closed door
	? = open door
	@ = player and door on the same spot
	| = player and egg on the same spot
	N, S, W, E = player

	If the player destination is in a spot with:
	- an open door
	- on an egg
	or it handles with ft_player_leaves_the_spot() any
	movement of the player from any spot to a 0 spot
*/

void	ft_update_minimap(t_cub3d *cub3d)
{
	if (cub3d->map_with_player[(int) cub3d->finish_pos_x] \
		[(int) cub3d->finish_pos_y] == '?'
		|| (cub3d->map_with_player[(int) cub3d->finish_pos_x] \
		[(int) cub3d->finish_pos_y] == '@'))
	{
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '0';
		cub3d->map_with_player[(int) cub3d->finish_pos_x] \
			[(int) cub3d->finish_pos_y] = '@';
	}
	else if ((cub3d->map_with_player[(int) cub3d->finish_pos_x] \
		[(int) cub3d->finish_pos_y] == '2')
		|| (cub3d->map_with_player[(int) cub3d->finish_pos_x] \
		[(int) cub3d->finish_pos_y] == '|'))
	{
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '0';
		cub3d->map_with_player[(int) cub3d->finish_pos_x] \
			[(int) cub3d->finish_pos_y] = '|';
	}
	else
	{
		ft_player_leaves_the_spot(cub3d);
	}
}

void	ft_player_leaves_the_spot(t_cub3d *cub3d)
{
	if (cub3d->map_with_player[(int) cub3d->start_pos_x] \
		[(int) cub3d->start_pos_y] == '2')
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '|';
	else if (cub3d->map_with_player[(int) cub3d->start_pos_x] \
		[(int) cub3d->start_pos_y] == '?'
		|| (cub3d->map_with_player[(int) cub3d->start_pos_x] \
		[(int) cub3d->start_pos_y] == '@'))
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '?';
	else if (cub3d->map_with_player[(int) cub3d->start_pos_x] \
		[(int) cub3d->start_pos_y] == '|')
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '2';
	else
		cub3d->map_with_player[(int) cub3d->start_pos_x] \
			[(int) cub3d->start_pos_y] = '0';
	cub3d->map_with_player[(int) cub3d->finish_pos_x] \
		[(int) cub3d->finish_pos_y] = 'N';
}
