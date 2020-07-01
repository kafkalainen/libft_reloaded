/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 09:44:05 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/30 09:44:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lst_addback(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}
