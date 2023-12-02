/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/02 21:35:28 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	key_hook(int keycode, t_cub3d	*cub3d)
{
	if(keycode == ESC)
		ft_exit("ADL PAGA", cub3d);
	return 0;
}

int	cross_exit(int keycode, t_cub3d	*cub3d)
{
	ft_exit("ADL PAGA", cub3d);
	return 0;
}

int	mouse_hook(int keycode, t_cub3d	*cub3d)
{

	// Stampiamo il codice del tasto premuto
	printf("Key pressed: %d\n", keycode);

	return 0;
}

int mouse_move_hook(int x, int y, t_cub3d	*cub3d)
{
    // Stampa delle coordinate del movimento del mouse
    printf("Mouse moved to (%d, %d)\n", x, y);

    // Aggiungi qui la logica per gestire il movimento del mouse

    return 0;
}

void	game(t_cub3d	*cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "SSCNAPOLI3D");
	cub3d->img.img = mlx_new_image(cub3d->mlx ,WIN_WIDTH, WIN_HEIGHT);

	//parte utile ma non necessaria in questa funzione
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits, &cub3d->img.line,
								&cub3d->img.endian);
	my_mlx_ceiling(&cub3d->img, cub3d->ceiling_int);
	my_mlx_floor(&cub3d->img, cub3d->floor_int);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	//fine parte utile ma non necessaria in questa funzione
	mlx_mouse_hook(cub3d->win, mouse_hook, cub3d->mlx);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
	mlx_hook(cub3d->win, 6, 1L << 6, mouse_move_hook, cub3d);
	mlx_hook(cub3d->win, 17, 1L << 17, cross_exit, game);
	mlx_mouse_hide(cub3d->mlx, cub3d->win);
	mlx_loop(cub3d->mlx);
}
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
	game(&cub3d);
	ft_exit("RIUSCITO TUTTO", &cub3d);
}

void	stampa_matrice_char(char **matrice)
{
	for (int i = 0; matrice[i]; i++)
		printf("%s\n", matrice[i]);
}
