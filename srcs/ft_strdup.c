/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 09:24:41 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/04 14:37:22 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (str != NULL)
	{
		while (src[i] != '\0')
		{
			str[i] = src[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
