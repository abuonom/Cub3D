/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:18:29 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/08 20:58:00 by misidori         ###   ########.fr       */
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

void	ft_error_map_not_valid(t_cub3d *cub3d)
{
	write(2, "Error\nMap not valid\n", 22);
	ft_free_array(cub3d->map);
	exit(1);
}

int	ft_check_characters(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != 'N' && array[i][j] != 'S' && array[i][j] != 'W'
			&& array[i][j] != 'E' && array[i][j] != '0' && array[i][j] != '1'
			&& array[i][j] != '2' && array[i][j] != 'D' && array[i][j] != ' '
			&& array[i][j] != '\t')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
