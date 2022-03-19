/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <mcherki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:13:44 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/13 20:40:33 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	format(va_list ap, char c);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_putlhex(unsigned long num);
int	ft_putuhex(unsigned int num);
int	ft_putdmc(unsigned int num);

#endif
