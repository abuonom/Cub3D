/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/02 03:54:49 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	init_cub3d(&cub3d);
	check_extension(argc, argv, &cub3d);
	check_parameter(argc, argv, &cub3d);
	check_and_init_map(argv[1], &cub3d);
	init_trgb(&cub3d);
	stampa_matrice_char(cub3d.map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_ceiling(&img, cub3d.ceiling_int);
	my_mlx_floor(&img, cub3d.floor_int);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	ft_exit("RIUSCITO TUTTO", &cub3d);
}

void	stampa_matrice_char(char **matrice)
{
	for (int i = 0; matrice[i]; i++)
		printf("%s\n", matrice[i]);
}
