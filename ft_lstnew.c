/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 17:07:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/19 17:55:13 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_link;
	void		*new_content;
	size_t		new_size;

	new_size = content_size;
	new_content = (void*)content;
	if (content == NULL)
	{
		new_content = NULL;
		new_size = 0;
	}
	new_link = (t_list*)malloc(sizeof(*new_link));
	if (new_link != NULL)
	{
		new_link->content = (void*)malloc(sizeof(*new_content) * new_size);
		if (new_link->content != NULL)
		{
			new_link->content = new_content;
			new_link->content_size = new_size;
			new_link->next = NULL;
			return (new_link);
		}
		free(new_link);
	}
	return (NULL);
}
