/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:34:18 by alexigar          #+#    #+#             */
/*   Updated: 2023/12/28 11:58:34 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	to_hex(long nbr);
int		make_space(long n, int base);
char	*pointer_convert(void *ptr);
char	*nbr_convert(int nbr);
char	*unsigned_itoa(unsigned int n);
char	*upper_hex(int nbr);
char	*char_to_print(char to_print);
int		print(char const *ptr, void *arg, int to_return);
int		ft_printf(char const *str, ...);

#endif
