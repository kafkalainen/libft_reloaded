/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:58:46 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/17 10:54:45 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*temp;

	i = 0;
	temp = (char*)s;
	while (i < n && temp[i] != c)
		i++;
	if ((unsigned char)temp[i] == (unsigned char)c)
		return (void*)(s + i);
	else
		return (NULL);
}
