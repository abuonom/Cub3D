/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:32:50 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/06 17:57:02 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_load_texture(t_cub3d *cub3d)
{
	cub3d->wall->north_wall.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->NO, &cub3d->wall->north_wall.width, &cub3d->wall->north_wall.height);
	cub3d->wall->north_wall.addr = mlx_get_data_addr(cub3d->wall->north_wall.img, &cub3d->wall->north_wall.bits_per_pixel, &cub3d->wall->north_wall.line_length, &cub3d->wall->north_wall.endian);
	cub3d->wall->south_wall.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->SO, &cub3d->wall->south_wall.width, &cub3d->wall->south_wall.height);
	cub3d->wall->south_wall.addr = mlx_get_data_addr(cub3d->wall->south_wall.img, &cub3d->wall->south_wall.bits_per_pixel, &cub3d->wall->south_wall.line_length, &cub3d->wall->south_wall.endian);
	cub3d->wall->west_wall.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->WE, &cub3d->wall->west_wall.width, &cub3d->wall->west_wall.height);
	cub3d->wall->west_wall.addr = mlx_get_data_addr(cub3d->wall->west_wall.img, &cub3d->wall->west_wall.bits_per_pixel, &cub3d->wall->west_wall.line_length, &cub3d->wall->west_wall.endian);
 	cub3d->wall->east_wall.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->EA, &cub3d->wall->east_wall.width, &cub3d->wall->east_wall.height);
	cub3d->wall->east_wall.addr = mlx_get_data_addr(cub3d->wall->east_wall.img, &cub3d->wall->east_wall.bits_per_pixel, &cub3d->wall->east_wall.line_length, &cub3d->wall->east_wall.endian);
}
