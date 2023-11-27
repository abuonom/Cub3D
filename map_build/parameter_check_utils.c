/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:32:58 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/27 17:33:25 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_parameter(char *tmp, t_cub3d *cub3d)
{
	if (tmp[0] == 'N' && tmp[1] == 'O' && cub3d->NO == NULL)
		cub3d->NO = ft_strtrim(ft_strdup(tmp + 2), " ");
	if (tmp[0] == 'S' && tmp[1] == 'O' && cub3d->SO == NULL)
		cub3d->SO = ft_strtrim(ft_strdup(tmp + 2), " ");
	if (tmp[0] == 'W' && tmp[1] == 'E' && cub3d->WE == NULL)
		cub3d->WE = ft_strtrim(ft_strdup(tmp + 2), " ");
	if (tmp[0] == 'E' && tmp[1] == 'A' && cub3d->EA == NULL)
		cub3d->EA = ft_strtrim(ft_strdup(tmp + 2), " ");
	if (tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		cub3d->floor = ft_strtrim(ft_strdup(tmp + 2), " ");
	if (tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		cub3d->ceiling = ft_strtrim(ft_strdup(tmp + 2), " ");
}

int	is_param_not_present(char *tmp, t_cub3d *cub3d)
{
	if (tmp[0] == 'N' && tmp[1] == 'O' && cub3d->NO == NULL)
		return (1);
	if (tmp[0] == 'S' && tmp[1] == 'O' && cub3d->SO == NULL)
		return (1);
	if (tmp[0] == 'W' && tmp[1] == 'E' && cub3d->WE == NULL)
		return (1);
	if (tmp[0] == 'E' && tmp[1] == 'A' && cub3d->EA == NULL)
		return (1);
	if (tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		return (1);
	if (tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		return (1);
	return (0);
}

void	init_rgb(t_cub3d *cub3d)
{
	char	**tmp;

	tmp = ft_split(cub3d->floor, ',');
	cub3d->floor_rgb.r = ft_atoi(tmp[0]);
	cub3d->floor_rgb.g = ft_atoi(tmp[1]);
	cub3d->floor_rgb.b = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	tmp = ft_split(cub3d->ceiling, ',');
	cub3d->ceiling_rgb.r = ft_atoi(tmp[0]);
	cub3d->ceiling_rgb.g = ft_atoi(tmp[1]);
	cub3d->ceiling_rgb.b = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}
