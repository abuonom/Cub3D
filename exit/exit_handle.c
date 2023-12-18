/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:59 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/18 14:44:50 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int	i;

	if (map != NULL)
	{
		i = 0;
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d != NULL)
	{
		if (cub3d->win != NULL)
			mlx_clear_window(cub3d->mlx, cub3d->win);
		if (cub3d->img.img != NULL)
			mlx_destroy_image(cub3d->mlx, cub3d->img.img);
		if (cub3d->map != NULL)
			free_map(cub3d->map);
		if (cub3d->NO != NULL)
			free(cub3d->NO);
		if (cub3d->SO != NULL)
			free(cub3d->SO);
		if (cub3d->WE != NULL)
			free(cub3d->WE);
		if (cub3d->EA != NULL)
			free(cub3d->EA);
		if (cub3d->floor != NULL)
			free(cub3d->floor);
		if (cub3d->ceiling != NULL)
			free(cub3d->ceiling);
		if (cub3d->path != NULL)
			free(cub3d->path);
		if (cub3d->temp != NULL)
			free(cub3d->temp);
		if (cub3d->mlx != NULL)
			free(cub3d->mlx);
	}
}

void	ft_exit(char *str, t_cub3d *cub3d)
{
//	if (cub3d)
//		free_cub3d(cub3d);
	(void)	cub3d;
	printf("Error: %s\n", str);
	exit(1);
}
