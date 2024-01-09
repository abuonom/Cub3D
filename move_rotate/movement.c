/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/08 21:32:22 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dirY == 1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX
					+ cub3d->player.dirX
					* moveSpeed)][(int)cub3d->player.posY]))
			cub3d->player.posX += cub3d->player.dirX * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX)]
			[(int)(cub3d->player.posY + cub3d->player.dirY * moveSpeed)]))
			cub3d->player.posY += cub3d->player.dirY * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.posX;
		cub3d->finish_pos_y = cub3d->player.posY;
		ft_update_minimap(cub3d);
	}
}

void	backward_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dirY == -1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX
					- cub3d->player.dirX * moveSpeed)]
			[(int)cub3d->player.posY]))
			cub3d->player.posX -= cub3d->player.dirX * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)cub3d->player.posX]
				[(int)(cub3d->player.posY
					- cub3d->player.dirY * moveSpeed)]))
			cub3d->player.posY -= cub3d->player.dirY * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.posX;
		cub3d->finish_pos_y = cub3d->player.posY;
		ft_update_minimap(cub3d);
	}
}

void	left_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dirX == -1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX
					+ cub3d->player.dirY * moveSpeed)]
			[(int)cub3d->player.posY]))
			cub3d->player.posX += cub3d->player.dirY * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)cub3d->player.posX]
				[(int)(cub3d->player.posY
					- cub3d->player.dirX * moveSpeed)]))
			cub3d->player.posY -= (cub3d->player.dirX) * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.posX;
		cub3d->finish_pos_y = cub3d->player.posY;
		ft_update_minimap(cub3d);
	}
}

void	right_move(t_cub3d *cub3d, double moveSpeed)
{
	if (cub3d->player.mov_dirX == 1)
	{
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX
					- cub3d->player.dirY * moveSpeed)]
			[(int)cub3d->player.posY]))
			cub3d->player.posX -= cub3d->player.dirY * moveSpeed;
		if (ft_strrchr("02?", cub3d->map[(int)(cub3d->player.posX)]
			[(int)(cub3d->player.posY
				+ cub3d->player.dirX * moveSpeed)]))
			cub3d->player.posY += (cub3d->player.dirX) * moveSpeed;
		cub3d->finish_pos_x = cub3d->player.posX;
		cub3d->finish_pos_y = cub3d->player.posY;
		ft_update_minimap(cub3d);
	}
}

void	update_movement(t_cub3d *cub3d)
{
	double	move_speed;

	cub3d->start_pos_x = cub3d->player.posX;
	cub3d->start_pos_y = cub3d->player.posY;
	move_speed = cub3d->frameTime * 2.0;
	forward_move(cub3d, move_speed);
	backward_move(cub3d, move_speed);
	left_move(cub3d, move_speed);
	right_move(cub3d, move_speed);
}
