/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/21 20:36:07 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_camera(float angle, t_cub3d *cube)
{
	double	new_dir_x;
	double	new_dir_y;
	double	new_plane_x;
	double	new_plane_y;

	angle = angle * M_PI / 180.0f;
	new_dir_x = cube->player.dirX * cos(angle)
		- cube->player.dirY * sin(angle);
	new_dir_y = cube->player.dirX * sin(angle)
		+ cube->player.dirY * cos(angle);
	new_plane_x = cube->player.planeX * cos(angle)
		- cube->player.planeY * sin(angle);
	new_plane_y = cube->player.planeX * sin(angle)
		+ cube->player.planeY * cos(angle);
	cube->player.dirX = new_dir_x;
	cube->player.dirY = new_dir_y;
	cube->player.planeX = new_plane_x;
	cube->player.planeY = new_plane_y;
}

void	rotate_right(t_cub3d *cube, double rotSpeed,
	double oldDirX, double oldPlaneX)
{
	rotSpeed = cube->frameTime * 3.0;
	if (cube->player.cam_dir == 1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(-rotSpeed)
			- cube->player.dirY * sin(-rotSpeed);
		cube->player.dirY = oldDirX * sin(-rotSpeed)
			+ cube->player.dirY * cos(-rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(-rotSpeed)
			- cube->player.planeY * sin(-rotSpeed);
		cube->player.planeY = oldPlaneX * sin(-rotSpeed)
			+ cube->player.planeY * cos(-rotSpeed);
	}
}

void	rotate_left(t_cub3d *cube, double rotSpeed,
	double oldDirX, double oldPlaneX)
{
	if (cube->player.cam_dir == -1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(rotSpeed)
			- cube->player.dirY * sin(rotSpeed);
		cube->player.dirY = oldDirX * sin(rotSpeed)
			+ cube->player.dirY * cos(rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(rotSpeed)
			- cube->player.planeY * sin(rotSpeed);
		cube->player.planeY = oldPlaneX * sin(rotSpeed)
			+ cube->player.planeY * cos(rotSpeed);
	}
}

void	update_rotation(t_cub3d *cube)
{
	double	rot_speed;
	double	old_dirx;
	double	old_plane_x;

	rot_speed = cube->frameTime * 3.0;
	rotate_right(cube, rot_speed, old_dirx, old_plane_x);
	rotate_left(cube, rot_speed, old_dirx, old_plane_x);
}
