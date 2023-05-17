/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:32:58 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:10:11 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_pointer(va_list args, char specifier)
{
	unsigned long long	nbr;
	int			len;

	(void)specifier;
	nbr = va_arg(args, unsigned long long);
	len = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	len += ft_putnbr_base(nbr, "0123456789abcdef", 0, 1);
	return (len);
}

int	ft_handle_percent(va_list args, char specifier)
{	
	(void)args;
	(void)specifier;
	write(1, "%%", 1);
	return (1);
}
