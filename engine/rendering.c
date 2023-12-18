/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:52:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/18 17:28:50 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	get_pixel(t_img *img, int x, int y)
{
	char	*dest;

	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (1);
	dest = img->addr + (y * img->line + x * (img->bits / 8));
	return (*(unsigned long *)dest);
}

void	render_map(t_cub3d *cube)
{
	t_render	data;
	int				x;
	double	zbuffer[WIN_WIDTH];

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data,cube);
		draw_vertical_line(&data, cube, x);
		zbuffer[x] = data.perpWallDist;
		x++;
	}
}
