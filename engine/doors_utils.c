/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:23:52 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/22 17:39:31 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static void	draw_door_1(t_cub3d *cub3d, t_sprite *spr)
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

static void	draw_door_2(t_cub3d *game, t_sprite *spr, t_sprite spr_print,
				double *zbuff)
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
				* game->door.width / spr->spr_w) / 256;
		if (spr->transf_y > 0 && spr->transf_y < zbuff[stripe])
		{
			v = spr->drawy[0] - 1;
			while (++v < spr->drawy[1])
			{
				d = (v) * 256 - WIN_HEIGHT * 128 + spr->spr_h * 128;
				tex[1] = ((d * game->egg.height) / spr->spr_h) / 256;
				color = get_pixel_sprite(&game->door, tex[0], tex[1]);
				if (color & 0x00FFFFFF)
					my_mlx_pixel_put(&game->img, stripe, v, color);
			}
		}
		stripe++;
	}
}

void	draw_door(t_cub3d *cub3d, double zbuffer)
{
	int			i;
	t_sprite	door;

	i = 0;
	while (i < cub3d->sprite_num)
	{
		if (cub3d->sprite[i].distance > .1)
		{
			door.x = (cub3d->doors[i].x) - cub3d->player.posY;
			door.y = (cub3d->doors[i].y) - cub3d->player.posX;
			door.inv_det = 1.0 / (cub3d->player.planeY
					* cub3d->player.dirX
					- cub3d->player.dirY * cub3d->player.planeX);
			door.transf_x = door.inv_det * (cub3d->player.dirX * door.x
					- cub3d->player.dirY * door.y);
			door.transf_y = door.inv_det * (-cub3d->player.planeX
					* door.x
					+ cub3d->player.planeY * door.y);
			door.spr_screen_x = (((double)(WIN_WIDTH) / 2.) * (1.
						+ door.transf_x / door.transf_y));
			draw_door_1(cub3d, &door);
			draw_door_2(cub3d, &door, cub3d->doors[i], &zbuffer);
		}
		i++;
	}
}
