/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:45 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/24 16:05:16 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stddef.h>
# include<unistd.h>

size_t	nb_var(const char *str);
size_t	ft_putnbr_usd(unsigned int nb, size_t rtn);
size_t	ft_putnbr_hex(unsigned int nb, size_t rtn, char x);
size_t	ft_putnbr(int nb, size_t rtn);
size_t	ft_putchar(char c, size_t rtn);
size_t	ft_putstr(char *str, size_t rtn);
int		check_if_var(const char *str, size_t z);
size_t	var_lib(const char *str, size_t z, size_t rtn, va_list argz);
int		ft_printf(const char *str, ...);
size_t	ft_putnbr_hex_p(unsigned long long nb, size_t rtn, char x, int rec);

#endif
