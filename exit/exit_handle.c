/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:59 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/29 18:37:00 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int i;

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
	}
}

void ft_exit(char *str, t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	perror(str);
	exit(1);
}
