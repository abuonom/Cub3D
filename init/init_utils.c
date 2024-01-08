/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:44:28 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/04 18:05:21 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_distance(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return (distance);
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
