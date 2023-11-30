/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:18:29 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/30 18:24:48 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	find_max(char **map)
{
	int		row;
	size_t	lenght;
	size_t	max_lenght;

	lenght = 0;
	row = 0;
	max_lenght = ft_strlen(map[row]);
	while (map[row] != NULL)
	{
		lenght = ft_strlen(map[row]);
		if (lenght > max_lenght)
			max_lenght = lenght;
		row++;
	}
	return (max_lenght);
}

void	resize_map(char **map)
{
	int		row;
	int		i;
	size_t	max_lenght;
	size_t	current_lenght;

	max_lenght = find_max(map);
	row = 0;
	while (map[row] != NULL)
	{
		current_lenght = ft_strlen(map[row]);
		if (current_lenght < max_lenght)
		{
			map[row] = ft_realloc(map[row], sizeof(char),
					ft_strlen(map[row]), (max_lenght + 1));
			if (map[row] == NULL)
				return ;
			i = current_lenght;
			while (i < max_lenght)
				map[row][i++] = ' ';
			map[row][max_lenght] = '\0';
		}
		row++;
	}
}
