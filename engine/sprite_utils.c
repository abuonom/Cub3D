/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:52:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/21 20:42:52 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	frame_sprite(t_cub3d *cub3d)
{
	if (cub3d->frame_count % 20 == 0)
	{
		cub3d->current_sprite++;
		if (cub3d->current_sprite > 4)
			cub3d->current_sprite = 1;
	}
	if (cub3d->current_sprite == 1)
		load_image(&cub3d->egg, "./assets/Egg1.xpm", cub3d);
	if (cub3d->current_sprite == 2)
		load_image(&cub3d->egg, "./assets/Egg2.xpm", cub3d);
	if (cub3d->current_sprite == 3)
		load_image(&cub3d->egg, "./assets/Egg3.xpm", cub3d);
	if (cub3d->current_sprite == 4)
		load_image(&cub3d->egg, "./assets/Egg4.xpm", cub3d);
}

unsigned long	get_pixel_sprite(t_xpm_img *img, int x, int y)
{
	char	*dest;

	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (1);
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned long *)dest);
}

unsigned long	get_pixel(t_img *img, int x, int y)
{
	char	*dest;

	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (1);
	dest = img->addr + (y * img->line + x * (img->bits / 8));
	return (*(unsigned long *)dest);
}

void	sort_sprites(t_cub3d *cub3d)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < cub3d->sprite_num)
	{
		j = 0;
		while (j < cub3d->sprite_num - 1)
		{
			if (cub3d->sprite[j].distance < cub3d->sprite[j + 1].distance)
			{
				tmp = cub3d->sprite[j];
				cub3d->sprite[j] = cub3d->sprite[j + 1];
				cub3d->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
