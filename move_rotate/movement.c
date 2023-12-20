/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:22 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:02 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward_move(t_cub3d *cub3d, double moveSpeed)
{
if (cub3d->player.mov_dirY == 1)
	{
		if (cub3d->map[(int)(cub3d->player.posX + cub3d->player.dirX * moveSpeed)][(int)cub3d->player.posY] == '0')
			cub3d->player.posX += cub3d->player.dirX * moveSpeed;
		if (cub3d->map[(int)(cub3d->player.posX)][(int)(cub3d->player.posY + cub3d->player.dirY * moveSpeed)] == '0')
			cub3d->player.posY += cub3d->player.dirY * moveSpeed;
	}
}
void	backward_move(t_cub3d *cub3d, double moveSpeed)
{
		if (cub3d->player.mov_dirY == -1)
	{
		if (cub3d->map[(int)(cub3d->player.posX - cub3d->player.dirX * moveSpeed)][(int)cub3d->player.posY] == '0')
			cub3d->player.posX -= cub3d->player.dirX * moveSpeed;
		if (cub3d->map[(int)cub3d->player.posX][(int)(cub3d->player.posY - cub3d->player.dirY * moveSpeed)] == '0')
			cub3d->player.posY -= cub3d->player.dirY * moveSpeed;
	}
}

void	left_move(t_cub3d *cub3d, double moveSpeed)
{
		if (cub3d->player.mov_dirX == -1)
	{
		if (cub3d->map[(int)(cub3d->player.posX - cub3d->player.dirY * moveSpeed)][(int)cub3d->player.posY] == '0')
			cub3d->player.posX -= cub3d->player.dirY * moveSpeed;
		if (cub3d->map[(int)(cub3d->player.posX)][(int)(cub3d->player.posY + cub3d->player.dirX * moveSpeed)] == '0')
			cub3d->player.posY += (cub3d->player.dirX) * moveSpeed;
	}
}

void	right_move(t_cub3d *cub3d, double moveSpeed)
{
		if (cub3d->player.mov_dirX == 1)
	{
		if (cub3d->map[(int)(cub3d->player.posX + cub3d->player.dirY * moveSpeed)][(int)cub3d->player.posY] == '0')
			cub3d->player.posX += cub3d->player.dirY * moveSpeed;
		if (cub3d->map[(int)cub3d->player.posX][(int)(cub3d->player.posY - cub3d->player.dirX * moveSpeed)] == '0')
			cub3d->player.posY -= (cub3d->player.dirX) * moveSpeed;
	}
}

void	update_movement(t_cub3d *cub3d)
{
	double moveSpeed;

	moveSpeed = cub3d->frameTime * 2.0;
	forward_move(cub3d, moveSpeed);
	backward_move(cub3d, moveSpeed);
	left_move(cub3d, moveSpeed);
	right_move(cub3d, moveSpeed);
}
