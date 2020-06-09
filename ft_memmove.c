/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:15:29 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/09 15:45:24 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	size_t		j;
	const char	*s;
	char		*d;
	char		*temp;

	i = 0;
	j = 0;
	s = src;
	d = dest;
	temp = (char*)malloc(sizeof(*temp) * (n));
	if (temp != NULL)
	{
		while (i < n)
		{
			temp[i] = s[i];
			i++;
		}
		while (j < n)
		{
			d[j] = temp[j];
			j++;
		}
		free(temp);
		return (dest);
	}
	else
		return (NULL);
}
