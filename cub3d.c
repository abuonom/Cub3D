/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/29 18:11:22 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->NO = NULL;
	cub3d->SO = NULL;
	cub3d->WE = NULL;
	cub3d->EA = NULL;
	cub3d->floor = NULL;
	cub3d->ceiling = NULL;
	cub3d->path = NULL;
	cub3d->temp = NULL;
	cub3d->mlx = NULL;
	cub3d->win = NULL;
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	init_cub3d(&cub3d);
	check_extension(argc, argv, &cub3d);
	check_parameter(argc, argv, &cub3d);
	init_rgb(&cub3d);
	check_and_init_map(argv[1],&cub3d);
	stampa_matrice_char(cub3d.map);
	ft_exit("RIUSCITO TUTTO", &cub3d);
}

void	stampa_matrice_char(char **matrice)
{
	for (int i = 0; matrice[i]; i++)
		printf("%s\n", matrice[i]);
}
