/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/21 22:59:10 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_tex_width_height(t_render *data, t_cub3d *cub3d)
{
	if (data->hit == 2)
	{
		data->texWidth = cub3d->door->width;
		data->texHeight = cub3d->door->height;
	}
	else if (data->side == 1)
	{
		if (data->rayDirY > 0)
		{
			data->texWidth = cub3d->wall->north_wall.width;
			data->texHeight = cub3d->wall->north_wall.height;
			return ;
		}
		data->texWidth = cub3d->wall->south_wall.width;
		data->texHeight = cub3d->wall->south_wall.height;
	}
	else
	{
		if (data->rayDirX > 0)
		{
			data->texWidth = cub3d->wall->east_wall.width;
			data->texHeight = cub3d->wall->east_wall.height;
			return ;
		}
		data->texWidth = cub3d->wall->west_wall.width;
		data->texHeight = cub3d->wall->west_wall.height;
	}
}

void	wall_pos_ray_pos_on_wall(t_render *data, t_cub3d *cub3d)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(WIN_HEIGHT / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawEnd >= WIN_HEIGHT)
		data->drawEnd = WIN_HEIGHT - 1;
	if (data->side == 0)
		data->wallX = cub3d->player.posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = cub3d->player.posX + data->perpWallDist * data->rayDirX;
	data->wallX -= (int)(data->wallX);
	set_tex_width_height(data, cub3d);
	data->texX = (int)(data->wallX * (double)data->texWidth);
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = data->texWidth - data->texX - 1;
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = data->texWidth - data->texX - 1;
}

void	set_color(t_render *data, t_cub3d *cube, int shift)
{
	if (data->hit == 2)
	{
		data->color = *(unsigned int *)(cube->door->addr + shift);
	}
	else if (data->side == 1)
	{
		if (data->rayDirY > 0)
			data->color = *(unsigned int *)
				(cube->wall->north_wall.addr + shift);
		else
			data->color = *(unsigned int *)
				(cube->wall->south_wall.addr + shift);
	}
	else
	{
		if (data->rayDirX > 0)
			data->color = *(unsigned int *)
				(cube->wall->east_wall.addr + shift);
		else
			data->color = *(unsigned int *)
				(cube->wall->west_wall.addr + shift);
	}
}

void	draw_tex_wall(t_render *data, t_cub3d *cube, int x)
{
	int	y;

	data->step = 1.0 * data->texHeight / data->lineHeight;
	data->texPos = (data->drawStart - WIN_HEIGHT
			/ 2 + data->lineHeight / 2) * data->step;
	y = data->drawStart;
	while (y < data->drawEnd)
	{
		data->texY = (int)data->texPos % data->texHeight;
		data->texPos += data->step;
		set_color(data, cube, 4 * (int)(data->texHeight
				* data->texY + data->texX));
		my_mlx_pixel_put(&cube->img, x, y++, data->color);
	}
}

void	draw_vertical_line(t_render *data, t_cub3d *cub3d, int x)
{
	int	i;

	i = 0;
	wall_pos_ray_pos_on_wall(data, cub3d);
	while (i < data->drawStart)
		my_mlx_pixel_put(&cub3d->img, x, i++, cub3d->ceiling_int);
	draw_tex_wall(data, cub3d, x);
	i = data->drawEnd;
	while (i < WIN_HEIGHT)
		my_mlx_pixel_put(&cub3d->img, x, i++, cub3d->floor_int);
}
