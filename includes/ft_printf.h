/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:48 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:54:36 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Includes

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>

// structure

typedef struct s_format
{
	char	specifier;
	int		(*f)(va_list args, char specifier);
}			t_format;

// Prototypes

int	ft_printf(const char *format, ...);

int	ft_handle_chars(va_list args, char specifier);
int	ft_handle_pointer(va_list args, char specifier);
int	ft_handle_percent(va_list args, char specifier);
int	ft_handle_number(va_list args, char specifier);

int	ft_strlen( char *s);
int	ft_putnbr_base(unsigned long long nbr, char *base, int is_upper, int is_un);

#endif