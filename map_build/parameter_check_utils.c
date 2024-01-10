/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:32:58 by abuonomo          #+#    #+#             */
/*   Updated: 2024/01/10 12:46:46 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_parameter(char *tmp, t_cub3d *cub3d)
{
	if (tmp[0] == 'N' && tmp[1] == 'O' && cub3d->no == NULL)
		cub3d->no = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
	if (tmp[0] == 'S' && tmp[1] == 'O' && cub3d->so == NULL)
		cub3d->so = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
	if (tmp[0] == 'W' && tmp[1] == 'E' && cub3d->we == NULL)
		cub3d->we = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
	if (tmp[0] == 'E' && tmp[1] == 'A' && cub3d->ea == NULL)
		cub3d->ea = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
	if (tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		cub3d->floor = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
	if (tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		cub3d->ceiling = ft_strtrim(ft_strtrim(ft_strdup(tmp + 2), " "), "\n");
}

int	is_param_not_present(char *tmp, t_cub3d *cub3d)
{
	if (tmp[0] == 'N' && tmp[1] == 'O' && cub3d->no == NULL)
		return (1);
	if (tmp[0] == 'S' && tmp[1] == 'O' && cub3d->so == NULL)
		return (1);
	if (tmp[0] == 'W' && tmp[1] == 'E' && cub3d->we == NULL)
		return (1);
	if (tmp[0] == 'E' && tmp[1] == 'A' && cub3d->ea == NULL)
		return (1);
	if (tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		return (1);
	if (tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		return (1);
	return (0);
}
