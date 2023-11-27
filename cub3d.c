/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:55:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/27 17:15:05 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	check_parameter(argc, argv, &cub3d);
	check_map(argv[1],&cub3d);
}

void	stampa_matrice_char(char **matrice)
{
	for (int i = 0; matrice[i]; i++)
		printf("%s\n", matrice[i]);
}
