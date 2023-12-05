/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:55 by misidori         ###   ########.fr       */
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
	if (i < 6)
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

int	check_xpm(t_cub3d *cub3d)
{
	char	**no_so_we_ea;
	char	buffer[BUFFER_SIZE];
	int		file_descriptor;
	int		bytes_read;
	int		i;

	no_so_we_ea = (char **) ft_calloc(5, sizeof(char *));
	no_so_we_ea[0] = ft_strdup(cub3d->NO);
	no_so_we_ea[1] = ft_strdup(cub3d->SO);
	no_so_we_ea[2] = ft_strdup(cub3d->WE);
	no_so_we_ea[3] = ft_strdup(cub3d->EA);
	no_so_we_ea[4] = NULL;
	i = -1;
	while (no_so_we_ea[++i])
		printf("no_so_we_ea[%d]: %s\n", i, no_so_we_ea[i]);
	i = 0;
	while (no_so_we_ea[i])
	{
		file_descriptor = open(no_so_we_ea[i], O_RDONLY);
		if (file_descriptor == -1)
		{
			printf("Impossibile aprire il file: %s\n", no_so_we_ea[i]);
			exit(EXIT_FAILURE);
		}
		bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			perror("Errore durante la lettura del file");
			close(file_descriptor);
			exit(EXIT_FAILURE);
		}
		// Controllo diretto dei byte per identificare un file XPM
		if (bytes_read >= 9
				&& buffer[0] == 0x2f && buffer[1] == 0x2a && buffer[2] == 0x20
				&& buffer[3] == 0x58 && buffer[4] == 0x50 && buffer[5] == 0x4d
				&& buffer[6] == 0x20 && buffer[7] == 0x2a && buffer[8] == 0x2f)
			printf("Il file sembra essere un file XPM.\n");
		else
			printf("Il file non sembra essere un file XPM.\n");
		close(file_descriptor);
		i++;
	}
	ft_free_array(no_so_we_ea);
	return 0;
}

void	validate_param(t_cub3d *cub3d)
{
//	check_xpm(cub3d);
	ft_remove_char_in_str(cub3d->floor, '\n');
	ft_remove_char_in_str(cub3d->ceiling, '\n');
	printf("%d, %d\n", ft_isdigit_str(cub3d->ceiling),ft_isdigit_str(cub3d->floor));
	if(ft_isdigit_str(cub3d->ceiling) == 1 || ft_isdigit_str(cub3d->floor) == 1)
		ft_exit("Colors not digit",cub3d);
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
	close(fd);
	validate_param(cub3d); //questa valida i parametri di texture e colori
	if (cub3d->temp != NULL)
		free(cub3d->temp);
}
