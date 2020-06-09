/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:58:46 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/09 14:05:47 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*temp;

	i = 0;
	temp = s;
	while (i < n && temp[i] != c)
		i++;
	if (temp[i] == c)
		return (void*)(s + i);
	else
		return (NULL);
}
