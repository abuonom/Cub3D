/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:41:27 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/17 15:46:09 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void stampaMatriceChar(char **matrice) {
    for (int i = 0; matrice[i]; i++) {
        printf("%s\n", matrice[i]);
    }
}

char *pick_map(char *path)
{
	int fd;
	char *tmp;
	int i;
	char *res;

	res = ft_strdup("");
	i = 6;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nFile not found");
	while(i != 0)
	{
		tmp = get_next_line(fd);
		if(tmp == NULL)
			break;
		if(tmp[0] != '\n')
			i--;
		free(tmp);
	}
	while(1)
	{
		tmp = get_next_line(fd);
		if(tmp == NULL)
			break;
		res = ft_strjoin3(res, tmp);
		free(tmp);
	}
	close(fd);
	return (res);
}

void check_map(char *path, t_cub3d *cub3d)
{
	cub3d->map = ft_split(pick_map(path),'\n');
	if(cub3d->map == NULL)
		ft_exit("Error\nMap not found");
	stampaMatriceChar(cub3d->map);
}



