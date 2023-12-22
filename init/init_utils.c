/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/22 17:41:22 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_distance(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return (distance);
}

void	ft_sprite_position(t_cub3d *cub3d)
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
			{
				cub3d->sprite[k].x = j + 0.5;
				cub3d->sprite[k].y = i + 0.5;
				cub3d->sprite[k].distance = ft_distance(cub3d->player.posX,
						cub3d->player.posY, cub3d->sprite[k].x,
						cub3d->sprite[k].y);
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_doors_position(t_cub3d *cub3d)
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
			if (cub3d->map[i][j] == 'D')
			{
				cub3d->doors[k].x = j + 0.5;
				cub3d->doors[k].y = i + 0.5;
				cub3d->doors[k].distance = ft_distance(cub3d->player.posX,
						cub3d->player.posY, cub3d->doors[k].x,
						cub3d->doors[k].y);
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_doors(t_cub3d *cub3d)
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
			if (cub3d->map[i][j] == 'D')
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	cub3d->door_num = k;
	cub3d->doors = ft_calloc(k + 1, sizeof(t_sprite));
	ft_doors_position(cub3d);
}
