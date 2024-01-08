/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_load_player_egg_imgs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:16 by misidori          #+#    #+#             */
/*   Updated: 2024/01/04 17:11:24 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_player_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->player_img,
		j * 15, (i + 1) * 15);
}

void	ft_put_egg_img_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->egg_img,
		j * 15, (i + 1) * 15);
}

void	ft_put_egg_and_player_img(t_cub3d *cube, int i, int j)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->egg_and_player_img,
		j * 15, (i + 1) * 15);
}
