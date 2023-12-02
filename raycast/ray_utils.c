/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:10:11 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/20 17:10:11 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	encode_color(t_trgb rgb)
{
	return (rgb.t << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void my_mlx_ceiling(t_img *data, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void my_mlx_floor(t_img *data, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}
