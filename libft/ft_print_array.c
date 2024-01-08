/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:54:51 by misidori          #+#    #+#             */
/*   Updated: 2023/12/18 16:55:11 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(char **array_strings)
{
	int	i;

	i = 0;
	while (array_strings[i])
	{
		printf("%s\n", array_strings[i]);
		i++;
	}
}
