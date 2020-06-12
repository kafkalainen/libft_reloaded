/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:01:24 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/12 15:34:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	char		*trimmed_str;
	size_t		nb_of_whitespaces;
	size_t		i;

	nb_of_whitespaces = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			nb_of_whitespaces++;
		i++;
	}
	trimmed_str = (char*)malloc(sizeof(*trimmed_str) * (ft_strlen(s) - nb_of_whitespaces + 1);
	i = 0;
	if (trimmed_str != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			else
			{
				trimmed_str[i] = s[i];
				i++;
			}
		}
		trimmed_str[i] = '\0'
	}
	return (trimmed_str);
}
