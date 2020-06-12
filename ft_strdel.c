/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:43:15 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/12 10:28:57 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

void		ft_strdel(char **as)
{
	size_t		i;

	i = 0;
	while (as[i] != 0)
	{
		free(as[i]);
		as[i] = NULL;
		i++;
	}
	free(as);
	as = NULL;
}
