/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:33:05 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/29 14:33:05 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_i(va_list args)
{
	int		i;
	int		n;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		str = "(NULL)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

int	ft_print_u(va_list args)
{
	char			*str;
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(args, unsigned int);
	str = ft_utoa(n);
	if (!str)
		str = "(NULL)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
