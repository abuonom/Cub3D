/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:01:55 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/13 21:01:55 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// la vista del tuo giocatore
void	ft_rad(t_cub3d *cub3d)
{
	int	i;
	int	angle;

	angle = cub3d->player.pov - 30.0;
	i = 0;
	while (i < WIN_WIDTH)
	{
		ft_pgtowall_dist(cub3d, angle, i);
		angle += 60.0 / WIN_WIDTH;
		i++;
	}
}

// distanza tra il giocatore e il muro
void	ft_pgtowall_dist(t_cub3d *cub3d, float angle, int i)
{
	float	sin_v;
	float	cos_v;
	float	dist;

	sin_v = sin(angle);
	cos_v = cos(angle);
	dist = 0.01;
	while (1)
	{
		if (cub3d->map[(int)(cub3d->player.ascisse_x + dist * cos_v)] \
		[(int)(cub3d->player.ordinate_y + dist * sin_v)] == '1')
			break ;
		dist += 0.01;
	}
	cub3d->radius_dim[i] = dist * cos (angle - (cub3d->player.pov * RAD));
	ft_orientation (cub3d, angle, dist, i);
}
//RAD dichiarato come la conversione di un grado in radianti
//(perchè le funzioni sin e cos vogliono i gradi in radianti)
//La distanza viene incrementata gradualmente fino a quando il 
//punto sulla mappa raggiunto dalla proiezione del raggio colpisce un muro
// orientationtamento del muro colpito dal raggio (nord,sud, est o ovest)

void	ft_orientation(t_cub3d *cub3d, float angle, float dist, int i)
{
	float	cos_value;
	float	sin_value;
	float	ascisse_x;
	float	ordinate_y;

	cos_value = cos(angle);
	sin_value = sin(angle);
	ascisse_x = cub3d->player.ascisse_x + dist * cos_value + 0.01;
	ordinate_y = cub3d->player.ordinate_y + dist * sin_value;
	if (cub3d->map[(int)(ordinate_y - 0.01)][(int)ascisse_x] == '1')
		cub3d->orientation[i] = NORTH; // nord
	else if (cub3d->map[(int)(ordinate_y + 0.01)][(int)ascisse_x] == '1')
		cub3d->orientation[i] = SOUTH; // sud
	else if (cub3d->map[(int)ordinate_y][(int)(ascisse_x - 0.01)] == '1')
		cub3d->orientation[i] = EAST; // est
	else
		cub3d->orientation[i] = WEST; // ovest
}

//L'orientationtamento viene assegnato a cub3d->orientationtation[i].
// (quindi se il muro è a nord, sud, est o ovest)

void ft_draw(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	k;
	int	color;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			if (j < (WIN_HEIGHT / 2) - (cub3d->wall_height / 2))
				color = cub3d->ceiling.r << 16 | cub3d->ceiling.g << 8 | \
				cub3d->ceiling.b;
			else if (j > (WIN_HEIGHT / 2) + (cub3d->wall_height / 2))
				color = cub3d->floor.r << 16 | cub3d->floor.g << 8 | \
				cub3d->floor.b;
			else
			{
				k = (int)((float)j / (float)WIN_HEIGHT * 64.0);
				color = cub3d->texture[cub3d->orientation[i]][k][0] << 16 | \
				cub3d->texture[cub3d->orientation[i]][k][1] << 8 | \
				cub3d->texture[cub3d->orientation[i]][k][2];
			}
			cub3d->img.data[j * WIN_WIDTH + i] = color;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
}
