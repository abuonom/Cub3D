/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/04 19:08:31 by misidori         ###   ########.fr       */
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
