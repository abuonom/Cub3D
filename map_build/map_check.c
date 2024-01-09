/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:41:27 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/09 18:37:42 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*pick_map(char *path, t_cub3d *cub3d)
{
	int		fd;
	char	*tmp;
	int		i;
	char	*res;

	res = ft_strdup("");
	i = 6;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nFile not found", cub3d);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (tmp[0] != '\n' && i != 0)
			i--;
		else
			res = ft_strjoin3(res, tmp);
		free(tmp);
	}
	close(fd);
	return (res);
}

char	**copy_map(char **map)
{
	int		row;
	int		i;
	char	**copy_map;

	row = 0;
	while (map[row] != NULL)
		row++;
	copy_map = (char **)malloc((row + 1) * sizeof(char *));
	if (copy_map == NULL)
		return (NULL);
	i = -1;
	while (++i < row)
	{
		copy_map[i] = (char *)malloc((ft_strlen(map[i]) + 1) * sizeof(char));
		if (copy_map[i] == NULL)
		{
			while (i-- > 0)
				free(copy_map[i]);
			free(copy_map);
			return (NULL);
		}
		ft_strcpy(copy_map[i], map[i]);
	}
	copy_map[row] = NULL;
	return (copy_map);
}

static int	flood_fill(char **map, int x, int y)
{
	int	res;

	res = 0;
	if (map[y][x] != '$' && map[y][x] != 1)
	{
		if (map[y][x + 1] == '\0' || map[y + 1] == NULL ||
				x - 1 < 0 || y - 1 < 0)
			res = 1;
		else
		{
			map[y][x] = '$';
			if (map[y][x + 1] != '1' && map[y][x + 1] != 'D')
				res = flood_fill(map, x + 1, y);
			if (map[y][x - 1] != '1' && map[y][x - 1] != 'D' && res != 1)
				res = flood_fill(map, x - 1, y);
			if (map[y + 1][x] != '1' && map[y + 1][x] != 'D' && res != 1)
				res = flood_fill(map, x, y + 1);
			if (map[y - 1][x] != '1' && map[y - 1][x] != 'D' && res != 1)
				res = flood_fill(map, x, y - 1);
		}
	}
	return (res);
}

int	player_p(char flag, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strrchr("NSEW", map[i][j]))
			{
				if (flag == 'x')
					return (j);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	check_and_init_map(char *path, t_cub3d *cub3d)
{
	char	*str_map;
	char	**copy;

	str_map = pick_map(path, cub3d);
	cub3d->map = ft_split(str_map, '\n');
	free(str_map);
	if (ft_check_characters(cub3d->map) == 1)
		ft_error_map_not_valid(cub3d);
	if (cub3d->map == NULL)
		ft_exit("Error\nMap not found", cub3d);
	tab_with_spaces(cub3d->map);
	check_first_last_row(cub3d->map, cub3d);
	check_trash(cub3d->map, cub3d);
	check_duplicate(cub3d->map, cub3d);
	copy = copy_map(cub3d->map);
	if (flood_fill(copy, player_p('x', cub3d->map),
			player_p('y', cub3d->map)) != 0)
		ft_exit("Map not valid", cub3d);
	free_map(copy);
	resize_map(cub3d->map);
	spaces_with_zero(cub3d->map);
	cub3d->map_with_player = ft_copy_array(cub3d->map,
			ft_get_size_array(cub3d->map));
}
