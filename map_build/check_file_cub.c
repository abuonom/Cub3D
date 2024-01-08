/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/27 15:23:31 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_file_cub(int argc, char **argv, t_cub3d *cub3d)
{
	cub3d->fd = open(argv[1], O_RDONLY);
	if (cub3d->fd < 0)
		ft_exit("Error opening file", cub3d);
	cub3d->temp = get_next_line(cub3d->fd);
	if (cub3d->temp == NULL)
		ft_exit("Error opening file", cub3d);
	while (cub3d->temp != NULL)
	{
		if (ft_is_parameter(cub3d->temp))
		{
			if (is_param_not_present(cub3d->temp, cub3d))
				add_parameter(cub3d->temp, cub3d);
			else
				ft_exit("Duplicated parameter", cub3d);
		}
		else if (cub3d->temp[0] != '\n'
			&& ft_param_full(cub3d->temp, cub3d) < 6)
			break ;
		free(cub3d->temp);
		cub3d->temp = get_next_line(cub3d->fd);
	}
	close(cub3d->fd);
	ft_check_parameters(cub3d);
	free(cub3d->temp);
}

int	ft_is_parameter(char *str)
{
	if ((str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A')
		|| (str[0] == 'C' && str[1] == ' ')
		|| (str[0] == 'F' && str[1] == ' '))
	{
		return (1);
	}
	return (0);
}

int	ft_check_cub(char *path)
{
	int	i;

	i = ft_strlen(path);
	printf("stampa: %s\n", path);
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
		return (1);
	return (0);
}

int	ft_param_full(char *tmp, t_cub3d *cub3d)
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
	if (i < 6)
		ft_exit("Wrong parameter", cub3d);
	return (i);
}

void	ft_check_extension(int argc, char **argv, t_cub3d *cub3d)
{
	if (argc > 2 || argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_exit("Wrong arguments", cub3d);
	if (ft_check_cub(argv[1]))
		ft_exit("Wrong file extension", cub3d);
}
