/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 08:55:58 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/16 08:58:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', fd);
}
