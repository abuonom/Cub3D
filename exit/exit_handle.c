/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:59 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/27 17:09:52 by abuonomo         ###   ########.fr       */
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
	if (cub3d->win != NULL)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->img.img != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	if (cub3d->wall->north_wall.img != NULL)
		mlx_destroy_image(cub3d->mlx,cub3d->wall->north_wall.img);
	if (cub3d->wall->south_wall.img != NULL)
		mlx_destroy_image(cub3d->mlx,cub3d->wall->south_wall.img);
	if (cub3d->wall->east_wall.img != NULL)
		mlx_destroy_image(cub3d->mlx,cub3d->wall->east_wall.img);
	if (cub3d->wall->west_wall.img != NULL)
		mlx_destroy_image(cub3d->mlx,cub3d->wall->west_wall.img);
	if (cub3d->egg.img != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->egg.img);
	if (cub3d->door.img != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->door.img);
	if (cub3d->mlx != NULL)
		free(cub3d->mlx);
}

void free_cub3d_1(t_cub3d *cub3d)
{
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
}


void	ft_exit(char *str, t_cub3d *cub3d)
{
	free_cub3d_1(cub3d);
	printf("Chiuso per: %s\n", str);
	exit(1);
}

void	ft_exit_2(char *str, t_cub3d *cub3d)
{
	if (cub3d->map != NULL)
		free_map(cub3d->map);

	destroy_mlx(cub3d);
	free_cub3d_1(cub3d);
	printf("Chiuso per: %s\n", str);
	exit(1);
}
