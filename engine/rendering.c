/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:52:00 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:42:46 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_sprite_1(t_sprite *spr)
{
	spr->spr_h = fabs(WIN_HEIGHT / spr->transf_y);
	spr->drawy[0] = -spr->spr_h / 2 + WIN_HEIGHT / 2;
	if (spr->drawy[0] < 0)
		spr->drawy[0] = 0;
	spr->drawy[1] = spr->spr_h / 2 + WIN_HEIGHT / 2;
	if (spr->drawy[1] >= WIN_HEIGHT)
		spr->drawy[1] = WIN_HEIGHT - 1;
	spr->spr_w = fabs((WIN_HEIGHT / spr->transf_y));
	spr->drawx[0] = -spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[0] < 0)
		spr->drawx[0] = 0;
	spr->drawx[1] = spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[1] >= WIN_WIDTH)
		spr->drawx[1] = WIN_WIDTH - 1;
}

static void	draw_sprite_2(t_cub3d *game, t_sprite *spr, double *zbuff)
{
	int				v;
	int				stripe;
	int				d;
	int				tex[2];
	unsigned int	color;

	stripe = spr->drawx[0];
	while (stripe < spr->drawx[1])
	{
		tex[0] = (256 * (stripe - (-spr->spr_w / 2 + spr->spr_screen_x))
				* game->egg.width / spr->spr_w) / 256;
		if (spr->transf_y > 0 && spr->transf_y < zbuff[stripe])
		{
			v = spr->drawy[0] - 1;
			while (++v < spr->drawy[1])
			{
				d = (v) * 256 - WIN_HEIGHT * 128 + spr->spr_h * 128;
				tex[1] = ((d * game->egg.height) / spr->spr_h) / 256;
				color = get_pixel_sprite(&game->egg, tex[0], tex[1]);
				if (color & 0x00FFFFFF)
					my_mlx_pixel_put(&game->img, stripe, v, color);
			}
		}
		stripe++;
	}
}

void	draw_sprites(t_cub3d *cub3d, double z_buffer)
{
	int			i;
	t_sprite	spr;

	i = 0;
	while (i < cub3d->sprite_num)
	{
		if (cub3d->sprite[i].distance > .1)
		{
			spr.x = (cub3d->sprite[i].x) - cub3d->player.pos_y;
			spr.y = (cub3d->sprite[i].y) - cub3d->player.pos_x;
			spr.inv_det = 1.0 / (cub3d->player.plane_y
					* cub3d->player.dir_x
					- cub3d->player.dir_y * cub3d->player.plane_x);
			spr.transf_x = spr.inv_det * (cub3d->player.dir_x * spr.x
					- cub3d->player.dir_y * spr.y);
			spr.transf_y = spr.inv_det * (-cub3d->player.plane_x
					* spr.x
					+ cub3d->player.plane_y * spr.y);
			spr.spr_screen_x = (((double)(WIN_WIDTH) / 2.) * (1.
						+ spr.transf_x / spr.transf_y));
			draw_sprite_1(&spr);
			draw_sprite_2(cub3d, &spr, &z_buffer);
		}
		i++;
	}
}

void	render_map(t_cub3d *cube)
{
	t_render	data;
	int			x;
	double		z_buffer[WIN_WIDTH];

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data, cube);
		draw_vertical_line(&data, cube, x);
		z_buffer[x] = data.perp_wall_dist;
		x++;
	}
	sort_sprites(cube);
	frame_sprite(cube);
	draw_sprites(cube, *z_buffer);
}
