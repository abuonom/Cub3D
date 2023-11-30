/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:23:41 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/30 18:23:55 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_buffer_al(int fd, char **buffer)
{
	int	i;

	if (!buffer[fd])
	{
		buffer[fd] = (char *) malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer[fd])
			return (1);
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[fd][i] = 0;
			i++;
		}
	}
	return (0);
}

void	ft_free_buffer(int r, int fd, char **buffer)
{
	if (!r)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
}

int	ft_fill(char **str, char **buffer, int fd)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[fd][i] != '\n' && buffer[fd][i])
		i++;
	if (i)
	{
		*str = ft_realloc_get(*str, buffer[fd], i);
		if (!(*str))
			return (1);
		if (BUFFER_SIZE != 1)
			ft_movebuffer(buffer[fd], i);
	}
	return (0);
}

int	ft_check_error(int r, char *str, char *buffer)
{
	if (r < 0)
	{
		if (str)
			free(str);
		if (buffer)
			free(buffer);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_get(char *str, char *buffer, int step)
{
	int		len;
	char	*new;

	len = 0;
	while (str[len])
		len++;
	new = (char *) malloc((len + step + 1) * sizeof(char));
	if (!new)
	{
		if (str)
			free(str);
		return (NULL);
	}
	new[len + step] = 0;
	while (--step >= 0)
		new[len + step] = buffer[step];
	while (--len >= 0)
		new[len] = str[len];
	if (str)
		free(str);
	return (new);
}
