/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:41:41 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dir_y == 1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x
					+ cub3d->player.dir_x
					* moveSpeed)][(int)cub3d->player.pos_y]))
			cub3d->player.pos_x += cub3d->player.dir_x * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x)]
			[(int)(cub3d->player.pos_y + cub3d->player.dir_y * moveSpeed)]))
			cub3d->player.pos_y += cub3d->player.dir_y * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.pos_x;
		cub3d->finish_pos_y = cub3d->player.pos_y;
	}
}

void	backward_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dir_y == -1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x
					- cub3d->player.dir_x * moveSpeed)]
			[(int)cub3d->player.pos_y]))
			cub3d->player.pos_x -= cub3d->player.dir_x * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)cub3d->player.pos_x]
				[(int)(cub3d->player.pos_y
					- cub3d->player.dir_y * moveSpeed)]))
			cub3d->player.pos_y -= cub3d->player.dir_y * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.pos_x;
		cub3d->finish_pos_y = cub3d->player.pos_y;
	}
}

void	left_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dir_x == -1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x
					+ cub3d->player.dir_y * moveSpeed)]
			[(int)cub3d->player.pos_y]))
			cub3d->player.pos_x += cub3d->player.dir_y * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)cub3d->player.pos_x]
				[(int)(cub3d->player.pos_y
					- cub3d->player.dir_x * moveSpeed)]))
			cub3d->player.pos_y -= (cub3d->player.dir_x) * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.pos_x;
		cub3d->finish_pos_y = cub3d->player.pos_y;
	}
}

void	right_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dir_x == 1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x
					- cub3d->player.dir_y * moveSpeed)]
			[(int)cub3d->player.pos_y]))
			cub3d->player.pos_x -= cub3d->player.dir_y * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.pos_x)]
			[(int)(cub3d->player.pos_y
				+ cub3d->player.dir_x * moveSpeed)]))
			cub3d->player.pos_y += (cub3d->player.dir_x) * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.pos_x;
		cub3d->finish_pos_y = cub3d->player.pos_y;
	}
}

void	update_movement(t_cub3d *cub3d)
{
	double	move_speed;

	cub3d->start_pos_x = cub3d->player.pos_x;
	cub3d->start_pos_y = cub3d->player.pos_y;
	cub3d->finish_pos_x = cub3d->player.pos_x;
	cub3d->finish_pos_y = cub3d->player.pos_y;
	move_speed = cub3d->frame_time * 2.0;
	forward_move(cub3d, move_speed);
	backward_move(cub3d, move_speed);
	left_move(cub3d, move_speed);
	right_move(cub3d, move_speed);
	ft_update_minimap(cub3d);
}
