/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:41:24 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/13 20:42:30 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(unsigned long num)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		len += ft_putlhex(num / 16);
	len += ft_putchar(hex[num % 16]);
	return (len);
}

int	ft_putuhex(unsigned int num)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
		len += ft_putuhex(num / 16);
	len += ft_putchar(hex[num % 16]);
	return (len);
}

int	ft_putdmc(unsigned int num)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789";
	if (num > 9)
		len += ft_putdmc(num / 10);
	len += ft_putchar(hex[num % 10]);
	return (len);
}
