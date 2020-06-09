/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 08:40:25 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/09 09:54:59 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*temp;
	i = 0;
	temp = s;
	while (i < n)
	{
		 temp[i] = c;
		 i++;
	}
	return ((void*)temp);
}
