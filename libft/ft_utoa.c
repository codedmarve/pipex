/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:00:06 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/29 20:00:06 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ndigits(unsigned int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (i);
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		dgt;
	int		i;

	dgt = ft_ndigits(n);
	i = dgt;
	str = malloc(sizeof(char) * (dgt + 1));
	if (!str)
		return (NULL);
	while (i > 0)
	{
		str[--i] = (n % 10) + '0';
		n /= 10;
	}
	str[dgt] = '\0';
	return (str);
}
