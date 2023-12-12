/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/07 22:38:01 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void	rotate_right(t_cub3d *cube, double rotSpeed, double oldDirX, double oldPlaneX)
{


	rotSpeed = cube->frameTime * 3.0;
	if (cube->player.cam_dir == 1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(-rotSpeed) - cube->player.dirY * sin(-rotSpeed);
		cube->player.dirY = oldDirX * sin(-rotSpeed) + cube->player.dirY * cos(-rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(-rotSpeed) - cube->player.planeY * sin(-rotSpeed);
		cube->player.planeY = oldPlaneX * sin(-rotSpeed) + cube->player.planeY * cos(-rotSpeed);
	}
}
void	rotate_left(t_cub3d *cube, double rotSpeed, double oldDirX, double oldPlaneX)
{
	if (cube->player.cam_dir == -1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(rotSpeed) - cube->player.dirY * sin(rotSpeed);
		cube->player.dirY = oldDirX * sin(rotSpeed) + cube->player.dirY * cos(rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(rotSpeed) - cube->player.planeY * sin(rotSpeed);
		cube->player.planeY = oldPlaneX * sin(rotSpeed) + cube->player.planeY * cos(rotSpeed);
	}
}

void	update_rotation(t_cub3d *cube)
{
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	rotSpeed = cube->frameTime * 3.0;
	rotate_right(cube, rotSpeed, oldDirX, oldPlaneX);
	rotate_left(cube, rotSpeed, oldDirX, oldPlaneX);
}
