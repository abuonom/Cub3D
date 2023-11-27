/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/27 17:33:22 by abuonomo         ###   ########.fr       */
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
	return (i);
}

void	check_parameter(int argc, char **argv, t_cub3d *cub3d)
{
	char	*tmp;
	int		fd;

	if (argc > 2 || argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_exit("Wrong arguments");
	if (check_cub(argv[1]))
		ft_exit("Wrong file extension");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("Error opening file");
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (is_parameter(tmp))
		{
			if (is_param_not_present(tmp, cub3d))
				add_parameter(tmp, cub3d);
			else
				break ;
		}
		else
		{
			if (tmp[0] != '\n' && param_full(tmp, cub3d) < 6)
				break ;
		}
		free(tmp);
	}
	if (tmp != NULL)
		free(tmp);
	close(fd);
	if (param_full(tmp, cub3d) < 6)
		ft_exit("Wrong parameter");
	init_rgb(cub3d);
}
