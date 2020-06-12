/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:30:45 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/12 10:42:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./libft.h"

void		ft_memdel(void **ap)
{
	size_t		i;

	i = 0;
	while (ap[i] != NULL)
	{
		free(ap[i]);
		ap[i] = NULL;
		i++;
	}
	free(ap);
	ap = NULL;
}
