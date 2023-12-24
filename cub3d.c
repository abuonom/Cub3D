/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/25 00:13:31 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_pressed(int keycode, t_cub3d	*cub3d)
{
	if (keycode == W)
		cub3d->player.mov_dirY = 1;
	if (keycode == A)
		cub3d->player.mov_dirX = -1;
	if (keycode == S)
		cub3d->player.mov_dirY = -1;
	if (keycode == D)
		cub3d->player.mov_dirX = 1;
	if (keycode == LEFT)
		cub3d->player.cam_dir = 1;
	if (keycode == RIGHT)
		cub3d->player.cam_dir = -1;
	if (keycode == ESC)
		ft_exit("ADL PAGA", cub3d);
	if(keycode == SPACE)
	{
		handle_door(cub3d);
	}
	return (0);
}

int	key_hook_released(int keycode, t_cub3d	*cub3d)
{
	if (keycode == W)
		cub3d->player.mov_dirY = 0;
	if (keycode == A)
		cub3d->player.mov_dirX = 0;
	if (keycode == S)
		cub3d->player.mov_dirY = 0;
	if (keycode == D)
		cub3d->player.mov_dirX = 0;
	if (keycode == LEFT)
		cub3d->player.cam_dir = 0;
	if (keycode == RIGHT)
		cub3d->player.cam_dir = 0;
	if (keycode == ESC)
		ft_exit("ADL PAGA", cub3d);
	return (0);
}

int	mouse_move_hook(int x, int y, t_cub3d	*cub3d)
{
	double	normalized_x;
	double	max_rotation_angle;
	double	rotation_angle;
	double	new_rotation_angle;

	(void)y;
	mlx_mouse_hide(cub3d->mlx, cub3d->win);
	normalized_x = (2.0f * x) / WIN_WIDTH - 1.0f;
	max_rotation_angle = 180.0f;
	rotation_angle = max_rotation_angle * normalized_x;
	new_rotation_angle = rotation_angle;
	if (cub3d->player.rot_angle != 360)
		new_rotation_angle = cub3d->player.rot_angle
			- rotation_angle;
	new_rotation_angle = -new_rotation_angle;
	cub3d->player.rot_angle = rotation_angle;
	rotate_camera(new_rotation_angle, cub3d);
	return (0);
}

void	game(t_cub3d	*cub3d)
{
	mlx_hook(cub3d->win, 17, 1L << 17, cross_exit, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook_pressed, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, key_hook_released, cub3d);
	mlx_hook(cub3d->win, 6, 1L << 6, mouse_move_hook, cub3d);
	mlx_loop_hook(cub3d->mlx, game_loop, cub3d);
	mlx_mouse_hide(cub3d->mlx, cub3d->win);
	mlx_loop(cub3d->mlx);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc > 2 || argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_exit("Wrong arguments", &cub3d);
	init_cub3d(&cub3d);
	ft_check_file_cub(argc, argv, &cub3d);
	check_and_init_map(argv[1], &cub3d);
	init_cub3d_mlx(&cub3d);
	game(&cub3d);
	ft_exit("RIUSCITO TUTTO", &cub3d);
}
