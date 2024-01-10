/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:35:46 by misidori          #+#    #+#             */
/*   Updated: 2024/01/10 11:43:36 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_minimap(t_cub3d *cube)
{
	int	map_len;
	int	map_height;
	int	i;
	int	j;

	i = 0;
	j = 0;
	map_len = ft_strlen(cube->map[0]);
	map_height = ft_get_size_array(cube->map);
	while (cube->map[i])
	{
		j = -1;
		while (cube->map[i][++j])
			ft_draw_map(cube, i, j);
		i++;
	}
}

void	ft_draw_map(t_cub3d *cube, int i, int j)
{
	if (cube->map_with_player[i][j] == '1')
		ft_put_wall_map_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '0')
		ft_put_floor_map_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '2')
		ft_put_egg_img_img(cube, i, j);
	else if (cube->map_with_player[i][j] == 'D'
		&& (cube->map_with_player[i - 1][j] == '1'
		&& cube->map_with_player[i + 1][j] == '1'))
		ft_put_door_vertical_close_img(cube, i, j);
	else if (cube->map_with_player[i][j] == 'D'
		&& (cube->map_with_player[i][j - 1] == '1'
		&& cube->map_with_player[i][j + 1] == '1'))
		ft_put_door_horizontal_close_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '?'
		&& (cube->map_with_player[i - 1][j] == '1'
		&& cube->map_with_player[i + 1][j] == '1'))
		ft_put_door_vertical_open_img(cube, i, j);
	else
		ft_draw_map_2(cube, i, j);
}

void	ft_draw_map_2(t_cub3d *cube, int i, int j)
{
	if (cube->map_with_player[i][j] == '?'
		&& (cube->map_with_player[i][j - 1] == '1'
		&& cube->map_with_player[i][j + 1] == '1'))
		ft_put_door_horizontal_open_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '@'
		&& (cube->map_with_player[i - 1][j] == '1'
		&& cube->map_with_player[i + 1][j] == '1'))
		ft_put_door_vertical_open_player_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '@'
		&& (cube->map_with_player[i][j - 1] == '1'
		&& cube->map_with_player[i][j + 1] == '1'))
		ft_put_door_horizontal_open_player_img(cube, i, j);
	else if (cube->map_with_player[i][j] == '|')
		ft_put_egg_and_player_img(cube, i, j);
	else if (cube->map_with_player[i][j] == 'N'
		|| cube->map_with_player[i][j] == 'S'
		||cube->map_with_player[i][j] == 'W'
		|| cube->map_with_player[i][j] == 'E')
		ft_put_player_img(cube, i, j);
}

void	ft_upload_minimap_textures(t_cub3d *cub3d)
{
	int	size;

	size = 15;
	cub3d->wall_map = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/wall.xpm", &size, &size);
	cub3d->floor_map = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/floor.xpm", &size, &size);
	cub3d->egg_img = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/egg.xpm", &size, &size);
	cub3d->door_vertical_close = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_vertical_close.xpm", &size, &size);
	cub3d->door_horizontal_close = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_horizontal_close.xpm", &size, &size);
	cub3d->door_vertical_open = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_vertical_open.xpm", &size, &size);
	cub3d->door_horizontal_open = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_horizontal_open.xpm", &size, &size);
	cub3d->door_vertical_open_player = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_vertical_open_player.xpm", &size, &size);
	cub3d->door_horizontal_open_player = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/door_horizontal_open_player.xpm", &size, &size);
	cub3d->egg_and_player_img = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/egg_and_player.xpm", &size, &size);
	cub3d->player_img = mlx_xpm_file_to_image(cub3d->mlx,
			"./assets/minimap/player.xpm", &size, &size);
}
