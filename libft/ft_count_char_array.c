/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:18:44 by matteo            #+#    #+#             */
/*   Updated: 2024/01/02 12:08:48 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char_array(char const **array, char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	if (!array || !c)
		return (0);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == c)
				counter++;
		}
		i++;
	}
	return (counter);
}
