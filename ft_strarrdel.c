/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:33:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/07/03 13:06:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	**ft_strarrdel(char **as, size_t size)
{
	size_t		i;

	i = 0;
	if (as != NULL)
	{
		while (i < size)
		{
			ft_strdel(&as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
	return (NULL);
}
