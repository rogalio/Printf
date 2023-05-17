/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:24:55 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:21:43 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_number(va_list args, char specifier)
{	
	char	*base10;
	char	*base16;
	char	*base16_upper;

	base10 = "0123456789";
	base16 = "0123456789abcdef";
	base16_upper = "0123456789ABCDEF";
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_base(va_arg(args, int), base10, 0, 0));
	else if (specifier == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), base10, 0, 0));
	else if (specifier == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), base16, 0, 0));
	else if (specifier == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), base16_upper, 1, 0));
	else
		return (0);
}
