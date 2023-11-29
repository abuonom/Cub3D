/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/29 15:05:07 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_cub(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
		return (1);
	return (0);
}

int	is_parameter(char *str)
{
	if ((str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A')
		|| (str[0] == 'C' && str[1] == ' ')
		|| (str[0] == 'F' && str[1] == ' '))
		return (1);
	return (0);
}

int	param_full(char *tmp, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (cub3d->NO != NULL)
		i++;
	if (cub3d->SO != NULL)
		i++;
	if (cub3d->WE != NULL)
		i++;
	if (cub3d->EA != NULL)
		i++;
	if (cub3d->floor != NULL)
		i++;
	if (cub3d->ceiling != NULL)
		i++;
	if(i > 6)
		ft_exit("Wrong parameter", cub3d);
	return (i);
}

void	check_extension(int argc, char **argv, t_cub3d *cub3d)
{
	if (argc > 2 || argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_exit("Wrong arguments", cub3d);
	if (check_cub(argv[1]))
		ft_exit("Wrong file extension", cub3d);
}
void	check_parameter(int argc, char **argv, t_cub3d *cub3d)
{
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("Error opening file", cub3d);
	cub3d->temp = get_next_line(fd);
	while (cub3d->temp != NULL)
	{
		if (is_parameter(cub3d->temp))
		{
			if (is_param_not_present(cub3d->temp, cub3d))
				add_parameter(cub3d->temp, cub3d);
			else
				ft_exit("Parametro duplicato", cub3d);
		}
		else if (cub3d->temp[0] != '\n' && param_full(cub3d->temp, cub3d) < 6)
				break ;
		free(cub3d->temp);
		cub3d->temp = get_next_line(fd);
	}
	param_full(cub3d->temp, cub3d);
	close(fd);
	if (cub3d->temp != NULL)
		free(cub3d->temp);
}
