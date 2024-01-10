/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 13:22:58 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_file_cub(t_cub3d *cub3d)
{
	while (cub3d->temp != NULL)
	{
		if (ft_is_parameter(cub3d->temp))
		{
			if (is_param_not_present(cub3d->temp, cub3d))
				add_parameter(cub3d->temp, cub3d);
			else
			{
				write(2, "Closed: Duplicated parameter\n", 29);
				free(cub3d->temp);
				exit(1);
			}
		}
		else if (cub3d->temp[0] != '\n'
			&& ft_param_full(cub3d) < 6)
			break ;
		free(cub3d->temp);
		cub3d->temp = get_next_line(cub3d->fd);
	}
	close(cub3d->fd);
	ft_param_full(cub3d);
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
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
		return (1);
	return (0);
}

int	ft_param_full(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (cub3d->no != NULL)
		i++;
	if (cub3d->so != NULL)
		i++;
	if (cub3d->we != NULL)
		i++;
	if (cub3d->ea != NULL)
		i++;
	if (cub3d->floor != NULL)
		i++;
	if (cub3d->ceiling != NULL)
		i++;
	if (i < 6)
	{
		write(2, "Closed: Missing parameter\n", 26);
		free(cub3d->temp);
		exit(1);
	}
	return (i);
}

void	ft_check_extension(char **argv)
{
	if (ft_check_cub(argv[1]))
	{
		write(2, "Closed: Wrong extension\n", 24);
		exit(1);
	}
}
