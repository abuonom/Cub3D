/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/21 22:58:30 by abuonomo         ###   ########.fr       */
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
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (cube->player.posX
				- (int)data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = ((int)data->mapX + 1.0
				- cube->player.posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (cube->player.posY
				- (int)data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = ((int)data->mapY + 1.0
				- cube->player.posY) * data->deltaDistY;
	}
}

void	perform_dda(t_render *data, t_cub3d *cub3d)
{
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (cub3d->map[(int)data->mapX][(int)data->mapY] == '1')
			data->hit = 1;
	}
}

void	init_render_data(t_render *data, t_cub3d *cube, int x)
{
	data->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	data->rayDirX = cube->player.dirX + cube->player.planeX * data->cameraX;
	data->rayDirY = cube->player.dirY + cube->player.planeY * data->cameraX;
	data->mapX = (int)cube->player.posX;
	data->mapY = (int)cube->player.posY;
	if (data->rayDirX == 0)
		data->deltaDistX = 1e30;
	else
		data->deltaDistX = fabs(1.0f / data->rayDirX);
	if (data->rayDirY == 0)
		data->deltaDistY = 1e30;
	else
		data->deltaDistY = fabs(1.0f / data->rayDirY);
	data->hit = 0;
	init_step_direction(data, cube);
}
