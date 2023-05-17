/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librairies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:48:35 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:01:40 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen( char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, int is_upper, int is_un)
{
	unsigned long long	base_len;
	int					len;

	len = 0;
	base_len = ft_strlen(base);
	if ((long long)nbr < 0 && !is_un)
	{
		write(1, "-", 1);
		len++;
		nbr = -nbr;
	}
	if ((unsigned long long)nbr >= base_len)
	{
		len += ft_putnbr_base(nbr / base_len, base, is_upper, is_un);
		len += ft_putnbr_base(nbr % base_len, base, is_upper, is_un);
	}
	else
	{
		if (is_upper && base[nbr] >= 'a' && base[nbr] <= 'f')
			base[nbr] -= 32;
		write(1, &base[nbr], 1);
		len++;
	}
	return (len);
}
