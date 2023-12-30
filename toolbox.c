/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:05:40 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:40 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex_p(unsigned long long nb, size_t rtn, char x, int rec)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (nb == 0)
	{
		rtn = ft_putstr("(nil)", rtn);
		return (rtn);
	}
	if (rec == 0)
		rtn = ft_putstr("0x", rtn);
	rec = 1;
	if (nb <= 15)
		rtn = ft_putchar(hex_base[nb], rtn);
	else
	{
		rtn = ft_putnbr_hex_p(nb / 16, rtn, x, rec);
		rtn = ft_putchar(hex_base[nb % 16], rtn);
	}
	return (rtn);
}

size_t	ft_putnbr_usd(unsigned int nb, size_t rtn)
{
	if (nb >= 10)
	{
		rtn = ft_putnbr_usd(nb / 10, rtn);
		rtn = ft_putchar(nb % 10 + '0', rtn);
	}
	else
		rtn = ft_putchar(nb + '0', rtn);
	return (rtn);
}

size_t	ft_putnbr_hex(unsigned int nb, size_t rtn, char x)
{
	char	*hex_base;

	if (x == 'X')
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nb <= 15)
		rtn = ft_putchar(hex_base[nb], rtn);
	else
	{
		rtn = ft_putnbr_hex(nb / 16, rtn, x);
		rtn = ft_putchar(hex_base[nb % 16], rtn);
	}
	return (rtn);
}

size_t	ft_putnbr(int nb, size_t rtn)
{
	if (nb == -2147483648)
	{
		rtn = ft_putchar('-', rtn);
		rtn = ft_putnbr(2, rtn);
		rtn = ft_putnbr(147483648, rtn);
		return (rtn);
	}
	if (nb < 0)
	{
		rtn = ft_putchar('-', rtn);
		nb = nb * (-1);
		rtn = ft_putnbr(nb, rtn);
	}
	else if (nb >= 10)
	{
		rtn = ft_putnbr(nb / 10, rtn);
		rtn = ft_putchar((nb % 10) + '0', rtn);
	}
	else
		rtn = ft_putchar(nb + '0', rtn);
	return (rtn);
}

size_t	nb_var(const char *str)
{
	size_t	z;
	size_t	y;

	y = 0;
	z = 0;
	while (str[z])
	{
		if (str[z] == '%' && check_if_var(str, z) == 1)
			y++;
		z++;
	}
	return (y);
}
