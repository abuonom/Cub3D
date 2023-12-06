/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/06 18:00:37 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "SSCNAPOLI3D");
	cub3d->img.img = mlx_new_image(cub3d->mlx ,WIN_WIDTH, WIN_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits, &cub3d->img.line,
								&cub3d->img.endian);
	cub3d->wall = ft_calloc(1, sizeof(t_cardinals));
	cub3d->door = ft_calloc(1, sizeof(t_xpm_img));
	cub3d->player.posX = player_p('y',cub3d->map) + 0.5;
	cub3d->player.posY = player_p('x',cub3d->map) + 0.5;
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
	cub3d->map[player_p('y',cub3d->map)][player_p('x',cub3d->map)] = '0';
	write(1, "Cub3D initialized\n", 18);
	ft_load_texture(cub3d);
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
