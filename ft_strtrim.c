/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:01:24 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/12 22:50:55 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	char				*trimmed_str;
	unsigned int		i;
	size_t				len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	trimmed_str = (char*)malloc(sizeof(*trimmed_str) * (len - i + 1));
	if (trimmed_str != NULL)
		trimmed_str = ft_strsub(s, i, len - i);
	return (trimmed_str);
}
