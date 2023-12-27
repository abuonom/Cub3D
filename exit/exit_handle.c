/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:59 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/27 14:20:49 by abuonomo         ###   ########.fr       */
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

void	destroy_mlx(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	mlx_destroy_image(cub3d->mlx,cub3d->wall->north_wall.img);
	mlx_destroy_image(cub3d->mlx,cub3d->wall->south_wall.img);
	mlx_destroy_image(cub3d->mlx,cub3d->wall->east_wall.img);
	mlx_destroy_image(cub3d->mlx,cub3d->wall->west_wall.img);
	mlx_destroy_image(cub3d->mlx, cub3d->egg.img);
	mlx_destroy_image(cub3d->mlx, cub3d->door.img);
}

void	free_cub3d_1(t_cub3d *cub3d)
{
		write(1, "free cub3d\n", 11);
		destroy_mlx(cub3d);
		free_map(cub3d->map);
		free(cub3d->wall);
		free(cub3d->NO);
		free(cub3d->SO);
		free(cub3d->WE);
		free(cub3d->EA);
		free(cub3d->floor);
		free(cub3d->ceiling);
		free(cub3d->sprite);
		free(cub3d->temp);
		free(cub3d->mlx);
}

void	ft_exit(char *str, t_cub3d *cub3d)
{
	free_cub3d_1(cub3d);
	printf("Chiuso per: %s\n", str);
	exit(1);
}
