/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:52:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/17 23:39:40 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	get_pixel(t_img *img, int x, int y)
{
	char	*dest;

	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (1);
	dest = img->addr + (y * img->line + x * (img->bits / 8));
	return (*(unsigned long *)dest);
}

static void	draw_spritino(t_cub3d *cube, t_drawsprite *spr, t_object *obj,
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
				* obj->tex->w / spr->spr_w) / 256;
		if (spr->transf[1] > 0 && spr->transf[1] < zbuff[stripe])
		{
			v = spr->drawy[0] - 1;
			while (++v < spr->drawy[1])
			{
				d = (v) * 256 - WIN_WIDTH * 128 + spr->spr_h * 128;
				tex[1] = ((d * obj->tex->h) / spr->spr_h) / 256;
				color = get_pixel(&obj->tex->xpm, tex[0], tex[1]);
				if (color & 0x0FFFFFFF)
					my_mlx_pixel_put(&cube->img, stripe, v, color);
			}
		}
		stripe++;
	}
}

static void	draw_spritone(t_drawsprite *spr)
{
	spr->spr_h = fabs(WIN_HEIGHT / spr->transf[1]);
	spr->drawy[0] = -spr->spr_h / 2 + WIN_HEIGHT / 2;
	if (spr->drawy[0] < 0)
		spr->drawy[0] = 0;
	spr->drawy[1] = spr->spr_h / 2 + WIN_HEIGHT / 2;
	if (spr->drawy[1] >= WIN_HEIGHT)
		spr->drawy[1] = WIN_HEIGHT - 1;
	spr->spr_w = fabs((WIN_HEIGHT / spr->transf[1]));
	spr->drawx[0] = -spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[0] < 0)
		spr->drawx[0] = 0;
	spr->drawx[1] = spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[1] >= WIN_WIDTH)
		spr->drawx[1] = WIN_WIDTH - 1;
}

t_object	*add_sorted_object(t_object **sorted, t_object *obj)
{
	t_object	*first;
	t_object	*previous;

	if (!*sorted)
		return ((*sorted = obj));
	first = *sorted;
	previous = NULL;
	while (*sorted && obj->dist < (*sorted)->dist)
	{
		previous = *sorted;
		*sorted = (*sorted)->sort;
	}
	if (!previous)
	{
		obj->sort = *sorted;
		*sorted = obj;
	}
	else
	{
		obj->sort = previous->sort;
		previous->sort = obj;
		*sorted = first;
	}
	return (obj);
}

t_object	*sort_objects(t_cub3d *cube)
{
	t_object	*sorted;
	t_object	*objs;

	sorted = NULL;
	objs = cube->objs;
	while (objs)
	{
		objs->dist = powf(objs->y - cube->player.posY, 2.)
			+ powf(objs->x - cube->player.posX, 2.);
		objs->sort = NULL;
		add_sorted_object(&sorted, objs);
		objs = objs->next;
	}
	return (sorted);
}

void	draw_fires(t_cub3d *cube, double *zbuff)
{
	t_object		*obj;
	t_drawsprite	spr;

	obj = cube->sorted;
	while (obj)
	{
		if (obj->dist > .1)
		{
			spr.pos[0] = (obj->x + 0.5) - cube->player.posX;
			spr.pos[1] = (obj->y + 0.5) - cube->player.posY;
			spr.inv_det = 1.0 / (cube->player.planeX
					* cube->player.dirY
					- cube->player.dirX * cube->player.planeY);
			spr.transf[0] = spr.inv_det * (cube->player.dirY * spr.pos[0]
					- cube->player.dirX * spr.pos[1]);
			spr.transf[1] = spr.inv_det * (-cube->player.planeY
					* spr.pos[0]
					+ cube->player.planeX * spr.pos[1]);
			spr.spr_screen_x = (((double)(WIN_WIDTH) / 2.) * (1.
						+ spr.transf[0] / spr.transf[1]));
			draw_spritone(&spr);
			draw_spritino(cube, &spr, obj, zbuff);
		}
		obj = obj->sort;
	}
}

void	render_map(t_cub3d *cube)
{
	t_render	data;
	int				x;
	double	zbuffer[WIN_WIDTH];

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data,cube);
		draw_vertical_line(&data, cube, x);
		zbuffer[x] = data.perpWallDist;
		x++;
	}
	//draw_egg(cube,zbuffer);
}
