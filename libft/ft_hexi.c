/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:31:49 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/31 22:31:49 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hexi(unsigned int n)
{
	int	dgt;

	dgt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		dgt++;
		n /= 16;
	}
	return (dgt);
}

int	ft_chexi(int tmp)
{
	if (tmp == 10)
		tmp = 'a';
	else if (tmp == 11)
		tmp = 'b';
	else if (tmp == 12)
		tmp = 'c';
	else if (tmp == 13)
		tmp = 'd';
	else if (tmp == 14)
		tmp = 'e';
	else if (tmp == 15)
		tmp = 'f';
	return (tmp);
}

int	ft_chexxi(int tmp)
{
	if (tmp == 10)
		tmp = 'A';
	else if (tmp == 11)
		tmp = 'B';
	else if (tmp == 12)
		tmp = 'C';
	else if (tmp == 13)
		tmp = 'D';
	else if (tmp == 14)
		tmp = 'E';
	else if (tmp == 15)
		tmp = 'F';
	return (tmp);
}

void	ft_helphexi(char *str, unsigned int n, int dgt, char c)
{
	int	tmp;

	str[dgt] = '\0';
	dgt--;
	while (dgt >= 0)
	{
		tmp = n % 16;
		if (tmp > 9)
		{
			if (c == 'x')
				str[dgt] = ft_chexi(tmp);
			else if (c == 'X')
				str[dgt] = ft_chexxi(tmp);
		}
		else
			str[dgt] = tmp + 48;
		n /= 16;
		dgt--;
	}
}

char	*ft_puthexi(unsigned int n, char c)
{
	char	*str;
	int		dgt;

	dgt = ft_count_hexi(n);
	str = malloc(sizeof(char) * (dgt + 1));
	if (str == NULL)
		return (NULL);
	ft_helphexi(str, n, dgt, c);
	return (str);
}
