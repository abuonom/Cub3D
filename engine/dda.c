/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/22 18:58:48 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_tex_width_height(t_render *data, t_cub3d *cub3d)
{
	if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
		{
			data->tex_width = cub3d->wall->north_wall.width;
			data->tex_height = cub3d->wall->north_wall.height;
			return ;
		}
		data->tex_width = cub3d->wall->south_wall.width;
		data->tex_height = cub3d->wall->south_wall.height;
	}
	else
	{
		if (data->ray_dir_x > 0)
		{
			data->tex_width = cub3d->wall->east_wall.width;
			data->tex_height = cub3d->wall->east_wall.height;
			return ;
		}
		data->tex_width = cub3d->wall->west_wall.width;
		data->tex_height = cub3d->wall->west_wall.height;
	}
}

void	wall_pos_ray_pos_on_wall(t_render *data, t_cub3d *cub3d)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(WIN_HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_end >= WIN_HEIGHT)
		data->draw_end = WIN_HEIGHT - 1;
	if (data->side == 0)
		data->wall_x = cub3d->player.posY + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = cub3d->player.posX + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	set_tex_width_height(data, cub3d);
	data->tex_x = (int)(data->wall_x * (double)data->tex_width);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
}

void	set_color(t_render *data, t_cub3d *cube, int shift)
{
	if (data->hit == 2)
	{
		data->color = *(unsigned int *)(cube->door.addr + shift);
	}
	else if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
			data->color = *(unsigned int *)
				(cube->wall->north_wall.addr + shift);
		else
			data->color = *(unsigned int *)
				(cube->wall->south_wall.addr + shift);
	}
	else
	{
		if (data->ray_dir_x > 0)
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

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - WIN_HEIGHT
			/ 2 + data->line_height / 2) * data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos % data->tex_height;
		data->tex_pos += data->step;
		set_color(data, cube, 4 * (int)(data->tex_height
				* data->tex_y + data->tex_x));
		my_mlx_pixel_put(&cube->img, x, y++, data->color);
	}
}

void	draw_vertical_line(t_render *data, t_cub3d *cub3d, int x)
{
	int	i;

	i = 0;
	wall_pos_ray_pos_on_wall(data, cub3d);
	while (i < data->draw_start)
		my_mlx_pixel_put(&cub3d->img, x, i++, cub3d->ceiling_int);
	draw_tex_wall(data, cub3d, x);
	i = data->draw_end;
	while (i < WIN_HEIGHT)
		my_mlx_pixel_put(&cub3d->img, x, i++, cub3d->floor_int);
}
