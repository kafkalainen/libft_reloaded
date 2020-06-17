/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:15:29 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/17 09:45:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	void		*temp;

	temp = (void*)malloc(sizeof(*temp) * (n));
	if (temp != NULL)
	{
		ft_memcpy(temp, src, n);
		ft_memcpy(dest, temp, n);
		free(temp);
		return (dest);
	}
	else
		return (NULL);
}
