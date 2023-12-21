/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_len_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:44:05 by misidori          #+#    #+#             */
/*   Updated: 2023/12/21 20:44:50 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen2(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

static int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}

int	ft_cmp_len_and_str(char *str1, char *str2, int len)
{
	if (!str1 || !str2 || !len)
		return (0);
	if (ft_strncmp2(str1, str2, len) == 0 && ft_strlen2(str2) == len)
		return (1);
	else
		return (-1);
}
