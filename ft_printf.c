/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:55:39 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/24 15:57:30 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c, size_t rtn)
{
	write(1, &c, 1);
	return (rtn + 1);
}

size_t	ft_putstr(char *str, size_t rtn)
{
	size_t	z;

	z = 0;
	if (!str)
	{
		rtn = ft_putstr("(null)", rtn);
		return (rtn);
	}
	while (str[z])
	{
		rtn = ft_putchar(str[z], rtn);
		z++;
	}
	return (rtn);
}

int	check_if_var(const char *str, size_t z)
{
	if (str[z + 1] == 'd' || str[z + 1] == 'c' || str[z + 1] == 's'
		|| str[z + 1] == 'p' || str[z + 1] == 'i' || str[z + 1] == 'u'
		|| str[z + 1] == 'x' || str[z + 1] == 'X' || str[z + 1] == '%')
		return (1);
	return (0);
}

size_t	var_lib(const char *str, size_t z, size_t rtn, va_list argz)
{
	if (str[z + 1] == 'd' || str[z + 1] == 'i')
		rtn = ft_putnbr(va_arg(argz, int), rtn);
	else if (str[z + 1] == 'c')
		rtn = ft_putchar(va_arg(argz, int), rtn);
	else if (str[z + 1] == 's')
		rtn = ft_putstr(va_arg(argz, char *), rtn);
	else if (str[z + 1] == 'p')
		rtn = ft_putnbr_hex_p(va_arg(argz, unsigned long long), rtn, 'p', 0);
	else if (str[z + 1] == 'u')
		rtn = ft_putnbr_usd(va_arg(argz, unsigned int), rtn);
	else if (str[z + 1] == 'x')
		rtn = ft_putnbr_hex(va_arg(argz, unsigned long long), rtn, 'x');
	else if (str[z + 1] == 'X')
		rtn = ft_putnbr_hex(va_arg(argz, unsigned long long), rtn, 'X');
	else if (str[z + 1] == '%')
		rtn = ft_putchar('%', rtn);
	return (rtn);
}

int	ft_printf(const char *str, ...)
{
	va_list		argz;
	size_t		rtn;
	size_t		z;

	z = 0;
	rtn = 0;
	va_start(argz, str);
	while (str[z])
	{
		if (str[z] == '%' && check_if_var(str, z) == 1)
		{
			rtn = var_lib(str, z, rtn, argz);
			z += 2;
		}
		else
		{
			rtn = ft_putchar(str[z], rtn);
			z++;
		}	
	}
	va_end(argz);
	return (rtn);
}
