/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:46:48 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/08 09:07:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft.h"
#include <string.h>

char		*ft_strrchr(const char *str, int c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && str[len - i] != c)
		i++;
	if (str[len - i] == c)
		return (char*)(str + (len - i));
	else
		return (NULL);
}
