/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_formats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:48:52 by alexigar          #+#    #+#             */
/*   Updated: 2023/12/22 10:58:12 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

char	*upper_hex(int nbr)
{
	char	*to_return;
	int		i;

	to_return = nbr_convert(nbr);
	i = 0;
	while (to_return[i] != '\0')
	{
		to_return[i] = ft_toupper(to_return[i]);
		i++;
	}
	return (to_return);
}
/*
int main(void)
{
	int prueba = 42;
	char *prueba2 = upper_hex(prueba);
	printf("Original: %X\n", prueba);
	printf("Nuevo: %s", prueba2);
}*/
