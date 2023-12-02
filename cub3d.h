/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:42:57 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/13 20:42:57 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WIN_WIDTH 1280.0
# define WIN_HEIGHT 420.0

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define RAD 0.0174533

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SHIFT 65505
# define SPACE 32

#define BLACK 0x000000
#define RED 0xff0000
#define GREEN 0x5d9560
#define WHITE 0xfdfbfb
#define PURPLE 0x9b329f

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;   //bits x pixel
	int		line; //line lenght
	int		endian;
	int		height;
	int		width;
} t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	pov;
}	t_player;

typedef struct s_rgb
{
	int		t;
	int		r;
	int		g;
	int		b;
}	t_trgb;

typedef struct s_cub3d
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			t_right;
	int			t_left;
	char		**map;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*floor;
	char		*ceiling;
	int			ceiling_int;
	int			floor_int;
	t_trgb		floor_rgb;
	t_trgb		ceiling_rgb;
	float		wall_height[(int) WIN_WIDTH];
	float		radius_dim[(int) WIN_WIDTH];
	t_player	player;
	t_img		img;
	void		*mlx;
	void		*win;
	t_img		texture[4];
	char		*path;
	char		*temp;
	int			fd;
}	t_cub3d;

//mlx functions
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		encode_color(t_trgb rgb);
void	my_mlx_floor(t_img *data, int color);
void	my_mlx_ceiling(t_img *data, int color);
//exit functions
void	ft_exit(char *str, t_cub3d *cub3d);
void	free_map(char **map);
//check functions
void	check_parameter(int argc, char **argv, t_cub3d *cub3d);
void	check_and_init_map(char *path, t_cub3d *cub3d);
void	stampa_matrice_char(char **matrice);
void	tab_with_spaces(char **map);
void	check_duplicate(char **map, t_cub3d *cub3d);
void	check_trash(char **map, t_cub3d *cub3d);
void	check_first_last_row(char **map, t_cub3d *cub3d);
int		is_param_not_present(char *tmp, t_cub3d *cub3d);
void	add_parameter(char *tmp, t_cub3d *cub3d);
void	check_extension(int argc, char **argv, t_cub3d *cub3d);
void	spaces_with_zero(char **map);
void	resize_map(char **map);
//init functions
void	init_trgb(t_cub3d *cub3d);
void	init_cub3d(t_cub3d *cub3d);

#endif
