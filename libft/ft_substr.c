/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:11:40 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/02 11:11:40 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t i)
{
	char	*substr;
	size_t	total_len;
	size_t	counter;

	if (!s)
		return (NULL);
	if (!i || start >= (ft_strlen(s)))
		return (ft_strdup(""));
	substr = malloc(i * sizeof(char) + 1);
	if (substr == 0)
		return (NULL);
	total_len = start + i;
	counter = 0;
	while (start < total_len)
	{
		substr[counter] = s[start];
		start++;
		counter++;
	}
	substr[counter] = 0;
	return (substr);
}
