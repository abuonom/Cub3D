/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:13:36 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/04 18:57:13 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

#include <stdio.h>
static int ft_isdigit_cub(int c)
{
    if ((c >= '0' && c <= '9') || c == ',' || c == ' ')
    {
        printf("ft_isdigit_cub -- res: %d\n", 0);
        return 0;
    }
    printf("ft_isdigit_cub -- res: %d\n", 1);
    return 1;
}

int ft_isdigit_str(char *str)
{
    int i = 0;
    int res = 0;
    printf("STR IN FT_IS_DIGIT -%s-\n", str);

    while (str[i] != '\0')
    {
        res = ft_isdigit_cub(str[i]);
        if (res == 1)
        {
            printf("res2 di %c: %d\n", str[i], res);
            return res; // Se trova un carattere non valido, restituisce subito 1
        }
        i++;
    }

    // Se esce dal ciclo, significa che tutti i caratteri sono numeri, virgole o spazi
    printf("res2: %d\n", res);
    return res; // Restituisce 0 se tutti i caratteri sono numeri, virgole o spazi
}
