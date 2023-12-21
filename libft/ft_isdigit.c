/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:13:36 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/21 20:46:06 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isdigit_cub(int c)
{
	if ((c >= '0' && c <= '9') || c == ',' || c == ' ')
		return (0);
	return (1);
}

int	ft_isdigit_str(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = ft_isdigit_cub(str[i]);
		if (res == 1)
		{
			return (res);
		}
		i++;
	}
	return (res);
}
