/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:28:23 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/11 11:57:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*str1;
	const char		*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if ((unsigned char)str1[i] > (unsigned char)str2[i] ||
			(unsigned char)str1[i] < (unsigned char)str2[i])
		{
			return ((int)str1[i] - (int)str2[i]);
		}
		i++;
	}
	return (0);
}
