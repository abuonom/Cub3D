/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:53:08 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/30 17:02:59 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_positions_to_watch(t_cub3d *cube, int *pos)
{
	int	i;

	i = 0;
	if (cube->player.dirX > 0)
	{
		pos[i++] = cube->player.posY;
		pos[i++] = cube->player.posX + 1;
	}
	if (cube->player.dirX < 0)
	{
		pos[i++] = cube->player.posY;
		pos[i++] = cube->player.posX - 1;
	}
	if (cube->player.dirY > 0)
	{
		pos[i++] = cube->player.posY + 1;
		pos[i++] = cube->player.posX;
	}
	if (cube->player.dirY < 0)
	{
		pos[i++] = cube->player.posY - 1;
		pos[i++] = cube->player.posX;
	}
	pos[i] = 0;
}

void	handle_door(t_cub3d *cube)
{
	int	*pos;
	int	i;

	i = 0;
	pos = (int *)malloc(sizeof(int) * 7);
	set_positions_to_watch(cube, pos);
	while (pos[i] && pos[i + 1])
	{
		if (cube->map[pos[i + 1]][pos[i]] == 'D')
		{
			cube->map[pos[i + 1]][pos[i]] = '?';
			cube->map_with_player[pos[i + 1]][pos[i]] = '?';
		}
		else if (cube->map[pos[i + 1]][pos[i]] == '?')
		{
			cube->map[pos[i + 1]][pos[i]] = 'D';
			cube->map_with_player[pos[i + 1]][pos[i]] = 'D';
		}
		i += 2;
	}
	free(pos);
}

int	cross_exit(int keycode, t_cub3d	*cub3d)
{
	ft_exit("Aurelio ha pagato", cub3d);
	return (0);
}
