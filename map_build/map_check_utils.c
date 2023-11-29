/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:27:35 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/29 18:10:18 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void spaces_with_zero(char **map)
{
	int row;
	int col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
				map[row][col] = '0';
			col++;
		}
		row++;
	}
}

void	tab_with_spaces(char **map)
{
	int		row;
	size_t	lenght;
	int		col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		lenght = ft_strlen(map[row]);
		while (col < lenght)
		{
			if (map[row][col] == '\t')
			{
				map[row] = ft_realloc(map[row], sizeof(char), ft_strlen(map[row]), ft_strlen(map[row]) + 4);
				memmove(&map[row][col + 4],
					&map[row][col + 1], lenght - col);
				map[row][col++] = ' ';
				map[row][col++] = ' ';
				map[row][col++] = ' ';
				map[row][col++] = ' ';
				lenght += 3;
			}
			else
				col++;
		}
		row++;
	}
}

void	check_duplicate(char **map, t_cub3d *cub3d)
{
	int	flag;
	int	i;
	int	j;

	i = 0;
	flag = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strrchr("NSEW", map[i][j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		ft_exit("Player error", cub3d);
}

void	check_trash(char **map, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strrchr("NSEW 10", map[i][j]))
				ft_exit("Not valid character in map", cub3d);
			j++;
		}
		i++;
	}
}

void	check_first_last_row(char **map, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && (map[0][i] != ' '))
			ft_exit("Esco al primo", cub3d);
		i++;
	}
	i = 0;
	j = 0;
	while (map[j] != NULL)
		j++;
	while (map[j - 1][i] != '\0')
	{
		if (map[j - 1][i] != '1' && (map[j - 1][i] != ' '))
			ft_exit("Esco al secondo", cub3d);
		i++;
	}
}
