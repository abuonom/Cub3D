/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:52:00 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/05 17:55:46 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_map(t_cub3d *cube)
{
	t_render	data;
	int				x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data,cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}
