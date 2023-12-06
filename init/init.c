/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/05 18:06:12 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->NO = NULL;
	cub3d->SO = NULL;
	cub3d->WE = NULL;
	cub3d->EA = NULL;
	cub3d->floor = NULL;
	cub3d->ceiling = NULL;
	cub3d->path = NULL;
	cub3d->temp = NULL;
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->img.img = NULL;
	cub3d->card = ft_calloc(1, sizeof(t_cardinals));
	cub3d->door = ft_calloc(1, sizeof(t_xpm_img));
	cub3d->player.posX = 10;
	cub3d->player.posY = 10;
	cub3d->player.dirX = -1;
	cub3d->player.dirY = 0;
	cub3d->player.planeX = 0;
	cub3d->player.planeY = 0.66;
	cub3d->player.mov_dirX = 0;
	cub3d->player.mov_dirY = 0;
	cub3d->player.cam_dir = 0;
	cub3d->player.rot_angle = 360;
	cub3d->time = 0;
	cub3d->oldTime = 0;
}

void	init_trgb(t_cub3d *cub3d)
{
	char	**tmp;

	tmp = ft_split(cub3d->floor, ',');
	cub3d->floor_rgb.r = ft_atoi(tmp[0]);
	cub3d->floor_rgb.g = ft_atoi(tmp[1]);
	cub3d->floor_rgb.b = ft_atoi(tmp[2]);
	cub3d->floor_rgb.t = 0;
	cub3d->floor_int = encode_color(cub3d->floor_rgb);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	tmp = ft_split(cub3d->ceiling, ',');
	cub3d->ceiling_rgb.r = ft_atoi(tmp[0]);
	cub3d->ceiling_rgb.g = ft_atoi(tmp[1]);
	cub3d->ceiling_rgb.b = ft_atoi(tmp[2]);
	cub3d->ceiling_rgb.t = 0;
	cub3d->ceiling_int = encode_color(cub3d->ceiling_rgb);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}
