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
# include <errno.h>
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <sys/time.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdint.h>

# define WIN_WIDTH 900
# define WIN_HEIGHT 500
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
# define SPRITE "./assets/sprite/Egg1_23.xpm"
# define DOOR "./assets/porta.xpm"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_rgb
{
	int		t;
	int		r;
	int		g;
	int		b;
}	t_trgb;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	mov_dirX;
	double	mov_dirY;
	double	cam_dir;
	double	rot_angle;
}	t_player;

typedef struct s_xpm_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_xpm_img;

typedef struct s_render
{
		double			map_x;
	double				map_y;
	double				step_x;
	double				step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					tex_width;
	int					tex_height;
	int					tex_x;
	int					tex_y;
	unsigned int		color;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				wall_x;
	double				step;
	double				tex_pos;
}	t_render;

typedef struct s_cardinals
{
	t_xpm_img	north_wall;
	t_xpm_img	south_wall;
	t_xpm_img	east_wall;
	t_xpm_img	west_wall;
}	t_cardinals;

typedef struct s_sprite_text
{
	t_xpm_img	egg;
}	t_sprite_text;

typedef struct s_sprite
{
	int				drawx[2];
	int				drawy[2];
	double			x;
	double			y;
	double			transf_x;
	double			transf_y;
	double			inv_det;
	double			distance;
	int				spr_screen_x;
	int				spr_h;
	int				spr_w;
}	t_sprite;

typedef struct s_tex {
	t_img	xpm;
	int		w;
	int		h;
}	t_tex;

typedef struct s_cub3d
{
	int				fd;
	int				ceiling_int;
	int				floor_int;
	int				fps;
	char			**map;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*floor;
	char			*ceiling;
	char			*path;
	char			*temp;
	float			wall_height[(int) WIN_WIDTH];
	float			radius_dim[(int) WIN_WIDTH];
	void			*mlx;
	void			*win;
	double			time;
	double			oldTime;
	double			frameTime;
	double			ZBuffer[(int)WIN_WIDTH];
	int				sprite_num;
	int				current_sprite;
	int				frame_count;
	t_xpm_img		egg;
	t_trgb			ceiling_rgb;
	t_trgb			floor_rgb;
	t_img			img;
	t_player		player;
	t_xpm_img		door;
	t_cardinals		*wall;
	t_sprite		*sprite;
}	t_cub3d;

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				encode_color(t_trgb rgb);
void			my_mlx_floor(t_img *data, int color);
void			my_mlx_ceiling(t_img *data, int color);
//exit functions
void			ft_exit(char *str, t_cub3d *cub3d);
void			free_map(char **map);
//check functions
void			check_and_init_map(char *path, t_cub3d *cub3d);
void			stampa_matrice_char(char **matrice);
void			tab_with_spaces(char **map);
void			check_duplicate(char **map, t_cub3d *cub3d);
void			check_trash(char **map, t_cub3d *cub3d);
void			check_first_last_row(char **map, t_cub3d *cub3d);
int				is_param_not_present(char *tmp, t_cub3d *cub3d);
void			add_parameter(char *tmp, t_cub3d *cub3d);
void			spaces_with_zero(char **map);
void			resize_map(char **map);
//init functions
void			init_trgb(t_cub3d *cub3d);
void			init_cub3d(t_cub3d *cub3d);
void			init_render_data(t_render *data, t_cub3d *cube, int x);
int				player_p(char flag, char **map);
void			init_cub3d_mlx(t_cub3d *cub3d);
//hook functions
int				cross_exit(int keycode, t_cub3d	*cub3d);
int				game_loop(t_cub3d *cube);
void			perform_dda(t_render *data, t_cub3d *cub3d);
void			draw_vertical_line(t_render *data, t_cub3d *cub3d, int x);
void			render_map(t_cub3d *cube);
void			handle_door(t_cub3d *cube);

/*	CHECK_FILE_CUB	*/

void			ft_check_file_cub(int argc, char **argv, t_cub3d *cub3d);
void			ft_check_extension(int argc, char **argv, t_cub3d *cub3d);
int				ft_param_full(char *tmp, t_cub3d *cub3d);
int				ft_is_parameter(char *str);
int				ft_check_cub(char *path);

/*	CHECK_PARAMETERS.C	*/

void			ft_check_parameters(t_cub3d *cub3d);
void			ft_init_array_files(t_cub3d *cub3d, char ***no_so_we_ea);
void			ft_check_magic_numbers(int bytes_read, char *buffer);
void			ft_check_single_file_type(char *file_image);
int				ft_check_file_xpm(t_cub3d *cub3d);

/*LOADING TEXTURE*/
void			ft_load_texture(t_cub3d *cub3d);
void			load_image(t_xpm_img *img, char *path, t_cub3d *cub3d);

/*MOVE*/
void			update_movement(t_cub3d *cube);
void			update_rotation(t_cub3d *cube);
void			rotate_camera(float angle, t_cub3d *cube);

/*SPRITE UTILS*/
void			sort_sprites(t_cub3d *cub3d);
void			frame_sprite(t_cub3d *cub3d);
unsigned long	get_pixel_sprite(t_xpm_img *img, int x, int y);
double			ft_distance(double x1, double y1, double x2, double y2);
void			ft_sprite_position(t_cub3d *cub3d);
void			ft_sleep(u_int64_t time);
u_int64_t		get_time(void);
#endif
