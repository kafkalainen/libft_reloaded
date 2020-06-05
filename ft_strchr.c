/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 12:47:22 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/05 15:10:50 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (char*)(s + i);
	else
		return (NULL);

}

/*if (s[i] == c)
		{
			ret = (char*)malloc(sizeof(*ret) * (ft_strlen(s) - i + 1));
			while (s[i] != '\0')
			{
				ret[j] = s[i];
				i++;
				j++;
			}
			ret[j] = '\0';
			return (ret);
		}*/
