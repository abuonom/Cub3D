/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:32:50 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/02 14:20:16 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_image(t_xpm_img *img, char *path, t_cub3d *cub3d)
{
	img->img = mlx_xpm_file_to_image(cub3d->mlx, path,
			&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	ft_load_texture(t_cub3d *cub3d)
{
	load_image(&cub3d->door, DOOR, cub3d);
	load_image(&cub3d->wall->north_wall, cub3d->NO, cub3d);
	load_image(&cub3d->wall->south_wall, cub3d->SO, cub3d);
	load_image(&cub3d->wall->west_wall, cub3d->WE, cub3d);
	load_image(&cub3d->wall->east_wall, cub3d->EA, cub3d);
	load_image(&cub3d->egg, SPRITE, cub3d);
	ft_upload_minimap_textures(cub3d);
}
