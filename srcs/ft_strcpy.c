/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:55:32 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/04 15:26:49 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <string.h>

char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
