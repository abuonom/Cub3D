/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/22 15:28:10 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	init_sprite(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cub3d->map[i])
	{
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == '2')
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	cub3d->sprite_num = k;
	cub3d->sprite = ft_calloc(k + 1, sizeof(t_sprite));
	ft_sprite_position(cub3d);
}
void player_direction(t_cub3d *cub3d)
{
	char	dir;
	dir = cub3d->map[player_p('y', cub3d->map)][player_p('x', cub3d->map)];
	if (dir == 'W')
	{
		cub3d->player.dirY = -1;
		cub3d->player.planeX = 0.66;
	}
	if (dir == 'E')
	{
		cub3d->player.dirY = 1;
		cub3d->player.planeX = -0.66;
	}
	if (dir == 'N')
	{
		cub3d->player.dirX = -1;
		cub3d->player.planeY = -0.66;
	}
	if (dir == 'S')
	{
		cub3d->player.dirX = 1;
		cub3d->player.planeY = 0.66;
	}
}
void	init_player(t_cub3d *cub3d)
{
	cub3d->player.posX = player_p('y', cub3d->map) + 0.5;
	cub3d->player.posY = player_p('x', cub3d->map) + 0.5;
	player_direction(cub3d);
	cub3d->player.mov_dirX = 0;
	cub3d->player.mov_dirY = 0;
	cub3d->player.cam_dir = 0;
	cub3d->player.rot_angle = 360;
	cub3d->map[player_p('y', cub3d->map)][player_p('x', cub3d->map)] = '0';
}

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH,
			WIN_HEIGHT, "SSCNAPOLI3D");
	cub3d->img.img = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits,
			&cub3d->img.line,
			&cub3d->img.endian);
	cub3d->wall = ft_calloc(1, sizeof(t_cardinals));
	cub3d->door = ft_calloc(1, sizeof(t_xpm_img));
	cub3d->oldTime = 0;
	cub3d->time = 0;
	cub3d->current_sprite = 1;
	cub3d->frame_count = 0;
	init_player(cub3d);
	init_sprite(cub3d);
	init_trgb(cub3d);
	ft_load_texture(cub3d);
}
