/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:41:41 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_fps(t_cub3d *cube)
{
	char	*number;

	cube->frame_count++;
	cube->old_time = cube->time;
	cube->time = get_time();
	cube->frame_time = (cube->time - cube->old_time) / 1000.0;
	cube->fps = (int)(1.0 / cube->frame_time);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frame_time) * 1000);
		cube->time = get_time();
		cube->frame_time = (cube->time - cube->old_time) / 1000.0;
		cube->fps = (int)(1.0 / cube->frame_time);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->win,
		WIN_WIDTH - 50, 20, -1, number);
	free(number);
}

int	game_loop(t_cub3d *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	ft_minimap(cube);
	return (0);
}
