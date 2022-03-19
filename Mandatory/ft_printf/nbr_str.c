/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:42:47 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/13 20:44:38 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "null", 6);
		return (6);
	}
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int	ft_putnbr(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		len += ft_putnbr(num / 10);
	len += ft_putchar(num % 10 + 48);
	return (len);
}
