/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:18:03 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/30 18:23:49 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
