/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_load_wall_floor_doors_imgs.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:16 by misidori          #+#    #+#             */
/*   Updated: 2024/01/04 17:11:34 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_wall_map_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->wall_map,
		j * 15, (i + 1) * 15);
}

void	ft_put_floor_map_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->floor_map,
		j * 15, (i + 1) * 15);
}

void	ft_put_door_vertical_close_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->door_vertical_close,
		j * 15, (i + 1) * 15);
}

void	ft_put_door_horizontal_close_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->door_horizontal_close,
		j * 15, (i + 1) * 15);
}
