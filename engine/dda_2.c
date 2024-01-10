/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:48:23 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

void	init_step_direction(t_render *data, t_cub3d *cube)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (cube->player.pos_x
				- (int)data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = ((int)data->map_x + 1.0
				- cube->player.pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (cube->player.pos_y
				- (int)data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = ((int)data->map_y + 1.0
				- cube->player.pos_y) * data->delta_dist_y;
	}
}

void	perform_dda(t_render *data, t_cub3d *cub3d)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (cub3d->map[(int)data->map_x][(int)data->map_y] == '1')
			data->hit = 1;
		if (cub3d->map[(int)data->map_x][(int)data->map_y] == 'D')
			data->hit = 2;
	}
}

void	init_render_data(t_render *data, t_cub3d *cube, int x)
{
	data->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	data->ray_dir_x = cube->player.dir_x
		+ cube->player.plane_x * data->camera_x;
	data->ray_dir_y = cube->player.dir_y
		+ cube->player.plane_y * data->camera_x;
	data->map_x = (int)cube->player.pos_x;
	data->map_y = (int)cube->player.pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0f / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0f / data->ray_dir_y);
	data->hit = 0;
	init_step_direction(data, cube);
}
