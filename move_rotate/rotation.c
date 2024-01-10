/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:41:41 by abuonomo         ###   ########.fr       */
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
	new_dir_x = cube->player.dir_x * cos(angle)
		- cube->player.dir_y * sin(angle);
	new_dir_y = cube->player.dir_x * sin(angle)
		+ cube->player.dir_y * cos(angle);
	new_plane_x = cube->player.plane_x * cos(angle)
		- cube->player.plane_y * sin(angle);
	new_plane_y = cube->player.plane_x * sin(angle)
		+ cube->player.plane_y * cos(angle);
	cube->player.dir_x = new_dir_x;
	cube->player.dir_y = new_dir_y;
	cube->player.plane_x = new_plane_x;
	cube->player.plane_y = new_plane_y;
}

void	rotate_right(t_cub3d *cube, double rotSpeed,
	double olddir_x, double oldplane_x)
{
	rotSpeed = cube->frame_time * 3.0;
	if (cube->player.cam_dir == 1)
	{
		olddir_x = cube->player.dir_x;
		cube->player.dir_x = cube->player.dir_x * cos(-rotSpeed)
			- cube->player.dir_y * sin(-rotSpeed);
		cube->player.dir_y = olddir_x * sin(-rotSpeed)
			+ cube->player.dir_y * cos(-rotSpeed);
		oldplane_x = cube->player.plane_x;
		cube->player.plane_x = cube->player.plane_x * cos(-rotSpeed)
			- cube->player.plane_y * sin(-rotSpeed);
		cube->player.plane_y = oldplane_x * sin(-rotSpeed)
			+ cube->player.plane_y * cos(-rotSpeed);
	}
}

void	rotate_left(t_cub3d *cube, double rotSpeed,
	double olddir_x, double oldplane_x)
{
	if (cube->player.cam_dir == -1)
	{
		olddir_x = cube->player.dir_x;
		cube->player.dir_x = cube->player.dir_x * cos(rotSpeed)
			- cube->player.dir_y * sin(rotSpeed);
		cube->player.dir_y = olddir_x * sin(rotSpeed)
			+ cube->player.dir_y * cos(rotSpeed);
		oldplane_x = cube->player.plane_x;
		cube->player.plane_x = cube->player.plane_x * cos(rotSpeed)
			- cube->player.plane_y * sin(rotSpeed);
		cube->player.plane_y = oldplane_x * sin(rotSpeed)
			+ cube->player.plane_y * cos(rotSpeed);
	}
}

void	update_rotation(t_cub3d *cube)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0;
	old_dir_x = 0;
	old_plane_x = 0;
	rot_speed = cube->frame_time * 3.0;
	rotate_right(cube, rot_speed, old_dir_x, old_plane_x);
	rotate_left(cube, rot_speed, old_dir_x, old_plane_x);
}
