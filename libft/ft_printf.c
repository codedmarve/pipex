/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:02:05 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/25 13:02:05 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(va_list args, const char *format, int *i, int *len)
{
	*i = *i + 1;
	if (format[*i] == 'c')
		*len += ft_print_c(args) - 2;
	else if (format[*i] == 's')
		*len += ft_print_s(args) - 2;
	else if (format[*i] == 'i' || format[*i] == 'd')
		*len += ft_print_i(args) - 2;
	else if (format[*i] == 'u')
		*len += ft_print_u(args) - 2;
	else if (format[*i] == 'x' || format[*i] == 'X')
		*len += ft_print_x(args, format[*i]) - 2;
	else if (format[*i] == 'p')
		*len += ft_print_p(args);
	else if (format[*i] == '%')
	{
		write(1, "%", 1);
		*len -= 1;
	}
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(format);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			check(args, format, &i, &len);
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
