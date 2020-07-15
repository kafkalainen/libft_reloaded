/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:21:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/07/15 17:40:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int value, int base)
{
	int		len;

	len = 0;
	while (value)
	{
		len++;
		value /= base;
	}
	if (value == 0)
		len = 1;
	return (len);
}

static void		ft_handle_corner_cases(int *pvalue, int *plen, int base, char **str)
{
	if (base == 10 && *pvalue == -2147483648)
	{
		*plen = 0;
		ft_strcpy(*str, "-2147483648");
	}
	if (*pvalue < 0)
	{
		*pvalue *= -1;
		if (base == 10)
			**str = '-';
	}
}

char    		*ft_itoa_base(int value, int base)
{
	char	arr[17];
	char	*ret_arr;
	int		value_len;

	if (base < 2 || base > 16)
		return (0);
	ft_strcpy(arr, "0123456789ABCDEF");
	value_len = ft_intlen(value, base);
	if(!(ret_arr = (char*)malloc(sizeof(*ret_arr) * (value_len + 1))))
		return (NULL);
	ft_handle_corner_cases(&value, &value_len, base, &ret_arr);
	ret_arr[value_len] = '\0'; 
	while (value_len)
	{
		ret_arr[value_len - 1] = arr[value % base];
		value /= base;
		value_len--;
	}
	return (ret_arr);
}
