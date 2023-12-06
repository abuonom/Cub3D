/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/05 18:06:56 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}


void	init_step_direction(t_render *data, t_cub3d *cube)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (cube->player.posX - (int)data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = ((int)data->mapX + 1.0 - cube->player.posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (cube->player.posY - (int)data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = ((int)data->mapY + 1.0 - cube->player.posY) * data->deltaDistY;
	}
}
void	perform_dda(t_render *data, t_cub3d *cub3d)
{
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (cub3d->map[(int)data->mapX][(int)data->mapY] == '1')
			data->hit = 1;
	}
}

void	init_render_data(t_render *data, t_cub3d *cube, int x)
{
	data->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	data->rayDirX = cube->player.dirX + cube->player.planeX * data->cameraX;
	data->rayDirY = cube->player.dirY + cube->player.planeY * data->cameraX;
	data->mapX = (int)cube->player.posX;
	data->mapY = (int)cube->player.posY;
	if (data->rayDirX == 0)
		data->deltaDistX = 1e30;
	else
		data->deltaDistX = fabs(1.0f / data->rayDirX);
	if (data->rayDirY == 0)
		data->deltaDistY = 1e30;
	else
		data->deltaDistY = fabs(1.0f / data->rayDirY);
	data->hit = 0;
	init_step_direction(data, cube);
}

void	set_tex_width_height(t_render *data, t_cub3d *cub3d)
{
	if (data->hit == 2)
	{
		data->texWidth = cub3d->door->width;
		data->texHeight = cub3d->door->height;
	}
	else if (data->side == 1)
	{
		if (data->rayDirY > 0)
		{
			data->texWidth = cub3d->card->north_wall.width;
			data->texHeight = cub3d->card->north_wall.height;
			return ;
		}
		data->texWidth = cub3d->card->south_wall.width;
		data->texHeight = cub3d->card->south_wall.height;
	}
	else
	{
		if (data->rayDirX > 0)
		{
			data->texWidth = cub3d->card->east_wall.width;
			data->texHeight = cub3d->card->east_wall.height;
			return ;
		}
		data->texWidth = cub3d->card->west_wall.width;
		data->texHeight = cub3d->card->west_wall.height;
	}
}

void	wallPos_rayPosOnWall(t_render *data, t_cub3d *cub3d)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(WIN_HEIGHT / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawEnd >= WIN_HEIGHT)
		data->drawEnd = WIN_HEIGHT - 1;
	if (data->side == 0)
		data->wallX = cub3d->player.posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = cub3d->player.posX + data->perpWallDist * data->rayDirX;
	data->wallX -= (int)(data->wallX);
	set_tex_width_height(data, cub3d);
	data->texX = (int)(data->wallX * (double)data->texWidth);
	if(data->side == 0 && data->rayDirX > 0)
		data->texX = data->texWidth - data->texX - 1;
	if(data->side == 1 && data->rayDirY < 0)
		data->texX = data->texWidth - data->texX - 1;
}
void	set_color(t_render *data, t_cub3d *cube, int shift)
{
	if (data->hit == 2)
	{
		data->color = *(unsigned int *)(cube->door->addr + shift);
	}
	else if (data->side == 1)
	{
		if (data->rayDirY > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr + shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr + shift);
	}
	else
	{
		if (data->rayDirX > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr + shift);
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr + shift);
	}
}

void	draw_tex_wall(t_render *data, t_cub3d *cube, int x)
{
	int	y;
	data->step = 1.0 * data->texHeight / data->lineHeight;
	data->texPos = (data->drawStart - WIN_HEIGHT / 2 + data->lineHeight / 2) * data->step;
	y = data->drawStart;
	while(y < data->drawEnd)
	{
		data->texY = (int)data->texPos % data->texHeight;
		data->texPos += data->step;
		set_color(data, cube, 4 * (int)(data->texHeight * data->texY + data->texX));
		my_mlx_pixel_put(&cube->img, x, y++, data->color);
	}
}


void	draw_vertical_line(t_render *data, t_cub3d *cub3d, int x)
{
	int	i;

	i = 0;
	wallPos_rayPosOnWall(data, cub3d);
	while (i < data->drawStart)
		my_mlx_pixel_put(&cub3d->img, x, i++, 0x000000FF);
	draw_tex_wall(data, cub3d, x);
	i = data->drawEnd;
	while (i < WIN_HEIGHT)
		my_mlx_pixel_put(&cub3d->img, x, i++, 0xFFFFFFFF);
}

void	calculate_fps(t_cub3d *cube)
{
	char *number;

	cube->oldTime = cube->time;
	cube->time = get_time();
	cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
	cube->fps = (int)(1.0 / cube->frameTime);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frameTime) * 1000);
		cube->time = get_time();
		cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
		cube->fps = (int)(1.0 / cube->frameTime);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->win,
		WIN_WIDTH - 50, 20, -1, number);
	free(number);
}
void	forward_backward(t_cub3d *cube, double moveSpeed)
{
	if (cube->player.mov_dirY == 1)
	{
		if (cube->map[(int)(cube->player.posX + cube->player.dirX * moveSpeed)][(int)cube->player.posY] == false)
			cube->player.posX += cube->player.dirX * moveSpeed;
		if (cube->map[(int)(cube->player.posX)][(int)(cube->player.posY + cube->player.dirY * moveSpeed)] == false)
			cube->player.posY += cube->player.dirY * moveSpeed;
	}
	if (cube->player.mov_dirY == -1)
	{
		if (cube->map[(int)(cube->player.posX - cube->player.dirX * moveSpeed)][(int)cube->player.posY] == false)
			cube->player.posX -= cube->player.dirX * moveSpeed;
		if (cube->map[(int)cube->player.posX][(int)(cube->player.posY - cube->player.dirY * moveSpeed)] == false)
			cube->player.posY -= cube->player.dirY * moveSpeed;
	}
}

void	left_right(t_cub3d *cube, double moveSpeed)
{
	if (cube->player.mov_dirX == -1)
	{
		if (cube->map[(int)(cube->player.posX - cube->player.dirY * moveSpeed)][(int)cube->player.posY] == false)
			cube->player.posX -= cube->player.dirY * moveSpeed;
		if (cube->map[(int)(cube->player.posX)][(int)(cube->player.posY + cube->player.dirX * moveSpeed)] == false)
			cube->player.posY += (cube->player.dirX) * moveSpeed;
	}
	if (cube->player.mov_dirX == 1)
	{
		if (cube->map[(int)(cube->player.posX + cube->player.dirY * moveSpeed)][(int)cube->player.posY] == false)
			cube->player.posX += cube->player.dirY * moveSpeed;
		if (cube->map[(int)cube->player.posX][(int)(cube->player.posY - cube->player.dirX * moveSpeed)] == false)
			cube->player.posY -= (cube->player.dirX) * moveSpeed;
	}
}

void	update_movement(t_cub3d *cube)
{
	double moveSpeed;

	moveSpeed = cube->frameTime * 5.0;
	forward_backward(cube, moveSpeed);
	left_right(cube, moveSpeed);
}

void	update_rotation(t_cub3d *cube)
{
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	rotSpeed = cube->frameTime * 3.0;
	if (cube->player.cam_dir == 1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(-rotSpeed) - cube->player.dirY * sin(-rotSpeed);
		cube->player.dirY = oldDirX * sin(-rotSpeed) + cube->player.dirY * cos(-rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(-rotSpeed) - cube->player.planeY * sin(-rotSpeed);
		cube->player.planeY = oldPlaneX * sin(-rotSpeed) + cube->player.planeY * cos(-rotSpeed);
	}
	if (cube->player.cam_dir == -1)
	{
		oldDirX = cube->player.dirX;
		cube->player.dirX = cube->player.dirX * cos(rotSpeed) - cube->player.dirY * sin(rotSpeed);
		cube->player.dirY = oldDirX * sin(rotSpeed) + cube->player.dirY * cos(rotSpeed);
		oldPlaneX = cube->player.planeX;
		cube->player.planeX = cube->player.planeX * cos(rotSpeed) - cube->player.planeY * sin(rotSpeed);
		cube->player.planeY = oldPlaneX * sin(rotSpeed) + cube->player.planeY * cos(rotSpeed);
	}
}

int	game_loop(t_cub3d *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}






