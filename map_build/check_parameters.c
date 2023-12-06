/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:47:17 by misidori          #+#    #+#             */
/*   Updated: 2023/12/06 16:18:11 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_parameters(t_cub3d *cub3d)
{
	ft_check_file_xpm(cub3d);
	ft_remove_char_in_str(cub3d->floor, '\n');
	ft_remove_char_in_str(cub3d->ceiling, '\n');
	if (ft_isdigit_str(cub3d->ceiling) == 1
		|| ft_isdigit_str(cub3d->floor) == 1)
	{
		ft_exit("Color parameters are not valid: insert only digit numbers",
			cub3d);
	}
}

int	ft_check_file_xpm(t_cub3d *cub3d)
{
	char	**no_so_we_ea;
	int		i;

	no_so_we_ea = NULL;
	ft_init_array_files(cub3d, &no_so_we_ea);
	i = 0;
	while (no_so_we_ea[i])
	{
		ft_check_single_file_type(no_so_we_ea[i]);
		i++;
	}
	ft_free_array(no_so_we_ea);
	return (0);
}

void	ft_init_array_files(t_cub3d *cub3d, char ***no_so_we_ea)
{
	(*no_so_we_ea) = (char **) ft_calloc(5, sizeof(char *));
	(*no_so_we_ea)[0] = ft_strdup(cub3d->NO);
	(*no_so_we_ea)[1] = ft_strdup(cub3d->SO);
	(*no_so_we_ea)[2] = ft_strdup(cub3d->WE);
	(*no_so_we_ea)[3] = ft_strdup(cub3d->EA);
	(*no_so_we_ea)[4] = NULL;
}

void	ft_check_single_file_type(char *file_image)
{
	char	buffer[BUFFER_SIZE + 1];
	int		file_descriptor;
	int		bytes_read;

	ft_remove_char_in_str(file_image, '\n');
	file_descriptor = open(file_image, O_RDONLY);
	if (file_descriptor == -1)
	{
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		printf("Error: %s\n", strerror(errno));
		close(file_descriptor);
		exit(1);
	}
	buffer[bytes_read] = '\0';
	ft_check_magic_numbers(bytes_read, buffer);
	if (close(file_descriptor) < 0)
	{
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

void	ft_check_magic_numbers(int bytes_read, char *buffer)
{
	if (!(bytes_read >= 9
			&& buffer[0] == 0x2f && buffer[1] == 0x2a && buffer[2] == 0x20
			&& buffer[3] == 0x58 && buffer[4] == 0x50 && buffer[5] == 0x4d
			&& buffer[6] == 0x20 && buffer[7] == 0x2a && buffer[8] == 0x2f))
	{
		printf("File image is not .xpm.\n");
		exit(1);
	}
}
