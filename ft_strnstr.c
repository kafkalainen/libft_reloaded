/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:16:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/08 11:33:16 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		little_len;

	i = 0;
	little_len = ft_strlen(little);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp((char*)(big + i), little, little_len) == 0)
				return (char*)(big + i);
		}
	i++;
	}
	return (NULL);
}
