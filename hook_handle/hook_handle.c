/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:53:08 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:40:01 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_positions_to_watch(t_cub3d *cube, int *pos)
{
	int	i;

	i = 0;
	if (cube->player.dir_x > 0)
	{
		pos[i++] = cube->player.pos_y;
		pos[i++] = cube->player.pos_x + 1;
	}
	if (cube->player.dir_x < 0)
	{
		pos[i++] = cube->player.pos_y;
		pos[i++] = cube->player.pos_x - 1;
	}
	if (cube->player.dir_y > 0)
	{
		pos[i++] = cube->player.pos_y + 1;
		pos[i++] = cube->player.pos_x;
	}
	if (cube->player.dir_y < 0)
	{
		pos[i++] = cube->player.pos_y - 1;
		pos[i++] = cube->player.pos_x;
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

void	ft_exit_cross(t_cub3d *cub3d)
{
	(void) cub3d;
	exit(1);
}

int	cross_exit(int keycode, t_cub3d	*cub3d)
{
	keycode = 0;
	ft_exit_cross(cub3d);
	return (0);
}
