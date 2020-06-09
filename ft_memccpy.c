/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:42:17 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/09 11:46:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	s = src;
	d = dest;
	while (i < n && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	if (s[i] == c)
	{
		d[i] = s[i];
		i++;
		return (dest + i);
	}
	else
		return (NULL);
}
