/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:09:16 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/24 15:30:03 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_word_counter(char const *s, char c)
{
	size_t			i;
	size_t			word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

static void		ft_divide_word(char const *s, size_t i, size_t len, char **arr)
{
	if (len > 0)
	{
		arr[i] = ft_strsub(s - len, 0, len);
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			word_len;
	size_t			word_count;
	char			**arr;

	i = -1;
	word_count = ft_word_counter(s, c);
	arr = (char**)malloc(sizeof(*arr) * (word_count + 1));
	if (arr != NULL)
	{
		while (++i < word_count)
		{
			word_len = 0;
			while (*s == c && *s != '\0')
				++s;
			while (*s != c && *s != '\0')
			{
				word_len++;
				++s;
			}
			ft_divide_word(s, i, word_len, arr);
		}
		arr[i] = '\0';
	}
	return (arr);
}
