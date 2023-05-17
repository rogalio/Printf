/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:28:26 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:21:23 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_chars(va_list args, char specifier)
{
	char	c;
	char	*str;
	int	len;

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		return (1);
	}
	else
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		write(1, str, len);
		return (len);
	}
	return (0);
}
