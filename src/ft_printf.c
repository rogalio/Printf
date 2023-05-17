/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:03:13 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/17 20:58:52 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	process_format_str(va_list args, const char *str, const t_format *handle_f)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			i = 0;
			while (handle_f[i].specifier)
			{
				if (*str == handle_f[i].specifier)
				{
					count += handle_f[i].f(args, handle_f[i].specifier);
					break ;
				}
				i++;
			}
		}
		else
			count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				count;
	const t_format	handle_f[] = {
	{'c', ft_handle_chars},
	{'s', ft_handle_chars},
	{'p', ft_handle_pointer},
	{'d', ft_handle_number},
	{'i', ft_handle_number},
	{'u', ft_handle_number},
	{'x', ft_handle_number},
	{'X', ft_handle_number},
	{'%', ft_handle_percent},
	{0, NULL}
	};

	va_start(args, str);
	count = process_format_str(args, str, handle_f);
	va_end(args);
	return (count);
}
