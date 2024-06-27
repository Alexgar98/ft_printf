/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:55:37 by alexigar          #+#    #+#             */
/*   Updated: 2023/12/29 13:47:49 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include <limits.h>

char	to_hex(long nbr)
{
	int	module;

	module = nbr % 16;
	if (module <= 9)
		return (module + '0');
	else
		return ('a' + (module - 10));
}

static int	make_space(size_t n, int base)
{
	int	i;

	i = 0;
	if (n < (size_t)base)
		return (i);
	while (n >= (size_t)base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*pointer_convert(void *ptr)
{
	char	*to_return;
	size_t	direction;
	int		i;

	direction = (size_t)ptr;
	i = make_space(direction, 16) + 3;
	to_return = malloc(i + 1);
	if (!to_return)
		return (NULL);
	to_return[0] = '0';
	to_return[1] = 'x';
	to_return[i] = '\0';
	i--;
	while (direction >= 16)
	{
		to_return[i] = to_hex(direction % 16);
		direction = direction / 16;
		i--;
	}
	to_return[2] = to_hex(direction);
	return (to_return);
}

char	*nbr_convert(int nbr)
{
	char	*to_return;
	int		i;
	long	nbr_long;

	nbr_long = (long)nbr;
	if (nbr < 0)
		nbr_long += 4294967296;
	i = make_space(nbr_long, 16) + 1;
	to_return = malloc(i + 1);
	if (!to_return)
		return (NULL);
	to_return[i] = '\0';
	i--;
	while (nbr_long >= 16)
	{
		to_return[i] = to_hex(nbr_long);
		nbr_long = nbr_long / 16;
		i--;
	}
	to_return[0] = to_hex(nbr_long);
	return (to_return);
}

char	*unsigned_itoa(unsigned int n)
{
	char	*to_return;
	int		i;

	i = make_space(n, 10) + 1;
	to_return = malloc(i + 1);
	if (to_return == NULL)
		return (NULL);
	to_return[i] = '\0';
	i--;
	while (n >= 10)
	{
		to_return[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	to_return[0] = n + '0';
	return (to_return);
}
/*
int main(void)
{
	void *prueba = (void *) 0;
	char *puntero = pointer_convert(prueba);
	//unsigned int pruebanum = LONG_MIN;
	//char *stringnum = nbr_convert(pruebanum);
	printf("Original:	%p\nnuevo:		%s\n", prueba, puntero);
	//printf("Original:	%x\nnuevo:		%s\n", pruebanum, stringnum);
	//printf("Original: %x\n", pruebanum);
	//printf("Nuevo: %s", nbr_convert(pruebanum));
}*/
