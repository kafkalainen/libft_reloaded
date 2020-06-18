/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:31:46 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/18 16:23:13 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
	return ;
}
