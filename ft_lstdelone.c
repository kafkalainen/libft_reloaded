/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 08:46:17 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/25 12:29:38 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *item;

	if (*alst != NULL)
	{
		item = *alst;
		*alst = item->next;
		del(item->content, item->content_size);
		free(item);
		item = NULL;
	}
}
