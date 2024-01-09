/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:59 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/09 18:32:06 by abuonomo         ###   ########.fr       */
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
	mlx_destroy_image(cub3d->mlx, cub3d->wall->north_wall.img);
	mlx_destroy_image(cub3d->mlx, cub3d->wall->south_wall.img);
	mlx_destroy_image(cub3d->mlx, cub3d->wall->east_wall.img);
	mlx_destroy_image(cub3d->mlx, cub3d->wall->west_wall.img);
	mlx_destroy_image(cub3d->mlx, cub3d->egg.img);
	mlx_destroy_image(cub3d->mlx, cub3d->door.img);
}

void	free_cub3d_mlx(t_cub3d *cub3d)
{
	destroy_mlx(cub3d);
	write(1, "Closed: Cub3D\n", 14);
	if (cub3d->map)
		free_map(cub3d->map);
	write(1, "Closed: Map\n", 12);
	if (cub3d->wall != NULL)
		free(cub3d->wall);
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
	if (cub3d->sprite != NULL)
		free(cub3d->sprite);
	if (cub3d->temp != NULL)
		free(cub3d->temp);
	if (cub3d->mlx != NULL)
		free(cub3d->mlx);
	if (cub3d->map_with_player != NULL)
		ft_free_array(cub3d->map_with_player);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->map)
		free_map(cub3d->map);
	if (cub3d->wall != NULL)
		free(cub3d->wall);
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
	if (cub3d->sprite != NULL)
		free(cub3d->sprite);
	if (cub3d->temp != NULL)
		free(cub3d->temp);
	if (cub3d->mlx != NULL)
		free(cub3d->mlx);
	if (cub3d->map_with_player != NULL)
		ft_free_array(cub3d->map_with_player);
}

void	ft_exit(char *str, t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	printf("Closed: %s\n", str);
	exit(1);
}
