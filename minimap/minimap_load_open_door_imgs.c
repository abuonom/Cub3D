/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_load_open_door_imgs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:16 by misidori          #+#    #+#             */
/*   Updated: 2024/01/04 17:26:10 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_door_vertical_open_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->door_vertical_open,
		j * 15, (i + 1) * 15);
}

void	ft_put_door_horizontal_open_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->door_horizontal_open,
		j * 15, (i + 1) * 15);
}

void	ft_put_door_vertical_open_player_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win,
		cube->door_vertical_open_player, j * 15, (i + 1) * 15);
}

void	ft_put_door_horizontal_open_player_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win,
		cube->door_horizontal_open_player, j * 15, (i + 1) * 15);
}
