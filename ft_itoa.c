/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:01:20 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/15 18:53:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_nb_assign(int len, char *str, int n)
{
	int		temp;

	temp = 0;
	while (n > 0)
	{
		temp = n % 10;
		str[len - 1] = temp + '0';
		n = n / 10;
		len--;
	}
}

static int		ft_change_sign(char *str, int n)
{
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	return (n);
}

char			*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*str;

	nb = n;
	len = 0;
	if (n < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str != NULL)
	{
		n = ft_change_sign(str, n);
		ft_nb_assign(len, str, n);
		str[len] = '\0';
	}
	return (str);
}
