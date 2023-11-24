/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:41:27 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/24 19:44:59 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	stampaMatriceChar(char **matrice)
{
	for (int i = 0; matrice[i]; i++)
		printf("%s\n", matrice[i]);
}

char	*pick_map(char *path)
{
	int		fd;
	char	*tmp;
	int		i;
	char	*res;

	res = ft_strdup("");
	i = 6;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nFile not found");
	while (i != 0)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (tmp[0] != '\n')
			i--;
		free(tmp);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		res = ft_strjoin3(res, tmp);
		free(tmp);
	}
	close(fd);
	return (res);
}

void	check_first_last_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && (map[0][i] != ' '))
			ft_exit("Esco al primo");
		i++;
	}
	i = 0;
	j = 0;
	while (map[j] != NULL)
		j++;
	while (map[j - 1][i] != '\0')
	{
		if (map[j - 1][i] != '1' && (map[j - 1][i] != ' '))
			ft_exit("Esco al secondo");
		i++;
	}
}

char	**copy_map(char **original_map)
{
    int		row;
	int		i;
	char	**copied_map;

	row = 0;
	while (original_map[row] != NULL)
		row++;
	copied_map = (char **)malloc((row + 1) * sizeof(char *));
	if (copied_map == NULL)
		return NULL;
	i = -1;
	while (++i < row)
	{
		copied_map[i] = (char *)malloc((ft_strlen(original_map[i]) + 1) * sizeof(char));
		if (copied_map[i] == NULL)
		{
			while (i-- > 0)
				free(copied_map[i]);
			free(copied_map);
		return (NULL);
		}
		ft_strcpy(copied_map[i], original_map[i]);
	}
	copied_map[row] = NULL;
	return (copied_map);
}


int	flood_fill(char **map,int x, int y)
{
	int	res;

	return (res);
}

int	player_p(char flag, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			j = 0;
			if (ft_strrchr("NSEW",map[i][j]))
			{
				if (flag == 'x')
					return (j);
				return (i);
			}
			j++;
		}
		i++;
	}
}


void	check_duplicate(char **map)
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
			if (ft_strrchr("NSEW",map[i][j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		ft_exit("Player error");
}

void	check_trash(char **map)
{
	int	i;
	int	j;

	i = 0;

	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strrchr("NSEW 10",map[i][j]))
				ft_exit("Not valid character in map");
			j++;
		}
		i++;
	}
}

void	tab_with_spaces(char** map)
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
				ft_memmove(&map[row][col + 4], &map[row][col + 1], lenght - col);
				map[row][col] = ' ';
				map[row][col + 1] = ' ';
				map[row][col + 2] = ' ';
				map[row][col + 3] = ' ';
				lenght += 3;
				col += 4;
			}
			else
				col++;
		}
		row++;
	}
}

void	check_map(char *path, t_cub3d *cub3d)
{
	cub3d->map = ft_split(pick_map(path), '\n');

	if (cub3d->map == NULL)
		ft_exit("Error\nMap not found");
	tab_with_spaces(cub3d->map);
	check_first_last_row(cub3d->map);
	check_trash(cub3d->map);
	check_duplicate(cub3d->map);
	//if(flood_fill(copy_map(cub3d->map),player_p('x',cub3d->map),player_p('y',cub3d->map)))
		stampaMatriceChar(copy_map(cub3d->map));
}


