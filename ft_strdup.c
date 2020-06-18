/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 09:24:41 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/17 12:29:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t		i;
	char		*str;

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
