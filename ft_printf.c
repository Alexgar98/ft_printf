/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:09:03 by alexigar          #+#    #+#             */
/*   Updated: 2023/12/29 14:19:44 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

char	*char_to_print(char to_print)
{
	char	*to_return;

	to_return = malloc(2);
	if (!to_return)
		return (NULL);
	to_return[0] = to_print;
	to_return[1] = '\0';
	return (to_return);
}

char	*string_to_print(char const *ptr, void *arg)
{
	if (*ptr == 'c')
		return (char_to_print((char) arg));
	else if (*ptr == 's')
	{
		if (arg)
			return ((char *) arg);
		else
			return ("(null)");
	}
	else if (*ptr == 'p')
		return (pointer_convert(arg));
	else if (*ptr == 'd' || *ptr == 'i')
		return (ft_itoa((int) arg));
	else if (*ptr == 'u')
		return (unsigned_itoa((unsigned int) arg));
	else if (*ptr == 'x')
		return (nbr_convert((int) arg));
	else if (*ptr == 'X')
		return (upper_hex((int) arg));
	else if (*ptr == '%')
		return (char_to_print('%'));
	else
		return (char_to_print(*ptr));
	return (NULL);
}

int	print(char const *ptr, void *arg, int to_return)
{
	char	*to_print;

	to_print = string_to_print(ptr, arg);
	if (!to_print)
		to_return = -1;
	else
	{
		if (*ptr == 'c' && *to_print == '\0')
		{
			ft_putchar_fd(*to_print, 1);
			to_return++;
		}
		else
		{
			ft_putstr_fd(to_print, 1);
			to_return += ft_strlen(to_print);
		}
		if (*ptr != 's')
			free(to_print);
	}
	return (to_return);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	void	*next_arg;
	int		to_return;

	va_start(args, str);
	to_return = 0;
	while (*str != '\0' && to_return >= 0)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			to_return++;
		}
		else
		{
			str++;
			if (*str != '%')
				next_arg = va_arg(args, char *);
			to_return = print(str, next_arg, to_return);
		}
		str++;
	}
	va_end(args);
	return (to_return);
}
/*
int main(void)
{
	//void *prueba = (void *)-14523;
	//char *prueba2 = NULL;
	printf(" Return original: %d\n", printf("%c %c", 0, '0'));
	ft_printf(" Return nuevo: %d", ft_printf("%c %c", 0, '0'));
}*/
