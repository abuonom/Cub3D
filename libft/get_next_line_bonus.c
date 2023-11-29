/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:18:03 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/29 15:18:05 by abuonomo         ###   ########.fr       */
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

void	ft_movebuffer(char *buffer, int step)
{
	int	i;

	i = 0;
	if (!step)
		return ;
	while (i < BUFFER_SIZE)
	{
		if (!buffer[i])
			break ;
		if (i < BUFFER_SIZE - step)
			buffer[i] = buffer[i + step];
		else
			buffer[i] = 0;
		i++;
	}
}

char	*ft_realloc_get(char *str, char *buffer, int step)
{
	char	*new;
	int		i;

	if (!step)
		return (str);
	if (!str)
	{
		new = (char *) malloc((step + 1) * sizeof(char));
		if (!new)
			return (NULL);
		i = 0;
		while (i < step)
		{
			new[i] = buffer[i];
			i++;
		}
		new[i] = 0;
	}
	else
		new = ft_strjoin_get(str, buffer, step);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*str;
	int			r;

	r = 1;
	str = NULL;
	if (ft_buffer_al(fd, buffer))
		return (NULL);
	while (r)
	{
		if (ft_fill(&str, buffer, fd))
			return (NULL);
		if (buffer[fd][0] == '\n')
		{
			str = ft_realloc_get(str, buffer[fd], 1);
			ft_movebuffer(buffer[fd], 1);
			break ;
		}
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (ft_check_error(r, str, buffer[fd]))
			return (NULL);
	}
	ft_free_buffer(r, fd, buffer);
	return (str);
}
