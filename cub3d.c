/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/06 15:11:23 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	key_hook(int keycode, t_cub3d	*cub3d)
{
	if(keycode == ESC)
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
	int image_h;
	int image_w;
	void *image;

	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "SSCNAPOLI3D");
	cub3d->img.img = mlx_new_image(cub3d->mlx ,WIN_WIDTH, WIN_HEIGHT);

	//parte utile ma non necessaria in questa funzione
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits, &cub3d->img.line,
								&cub3d->img.endian);
	// my_mlx_ceiling(&cub3d->img, cub3d->ceiling_int);
	// my_mlx_floor(&cub3d->img, cub3d->floor_int);
	// mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	// //fine parte utile ma non necessaria in questa funzione
	// mlx_mouse_hook(cub3d->win, mouse_hook, cub3d->mlx);
	// mlx_mouse_hide(cub3d->mlx, cub3d->win);
	mlx_hook(cub3d->win, 17, 1L << 17 , cross_exit, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
	mlx_hook(cub3d->win, 6, 1L << 6, mouse_move_hook, cub3d);
	ft_remove_char_in_str(cub3d->NO, '\n');
	printf("cub3d->NO: %s\n", cub3d->NO);
	image = mlx_xpm_file_to_image(cub3d->mlx, cub3d->NO, &image_h, &image_w);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, image, 0, 0);
	mlx_loop(cub3d->mlx);
}
int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	init_cub3d(&cub3d);
	ft_check_extension(argc, argv, &cub3d);
	ft_check_file_cub(argc, argv, &cub3d);
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



/*

PER MISIDORI CONTROLLO MAGIC NUMBER XPM




int main() {
    const char *file_path = "percorso_del_tuo_file"; // Sostituisci con il percorso del tuo file

    int file_descriptor = open(file_path, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Impossibile aprire il file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);

    if (bytes_read < 0) {
        perror("Errore durante la lettura del file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    // Controllo diretto dei byte per identificare un file XPM
    if (bytes_read >= 9 &&
        buffer[0] == 0x2f && buffer[1] == 0x2a && buffer[2] == 0x20 &&
        buffer[3] == 0x58 && buffer[4] == 0x50 && buffer[5] == 0x4d &&
        buffer[6] == 0x20 && buffer[7] == 0x2a && buffer[8] == 0x2f) {
        printf("Il file sembra essere un file XPM.\n");
    } else {
        printf("Il file non sembra essere un file XPM.\n");
    }

    close(file_descriptor);
    return 0;
}
*/

