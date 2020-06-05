/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 09:53:28 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/05 12:44:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>
/*strlcat() concatenate strings respectively.
strlcat() take the full size of the buffer.
Guarantee to NUL-terminate the result
as long as size is larger than 0 or, in the case of strlcat(),
as long as there is at least one byte free in dst).
Note that a byte for the NUL should be included in size.
strlcat() only operate on true ''C'' strings.
strlcat() both src and dst must be NUL-terminated.
The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
Return Values strlcat() functions return the total length of the string they
tried to create. For strlcat() that means the initial length of dst plus
the length of src. While this may seem somewhat confusing, it was done to
make truncation detection simple.

If strlcat() traverses size characters without finding a NUL,
the length of the string is considered to be size and the destination string will
not be NUL-terminated (since there was no space for the NUL). This keeps strlcat()
from running off the end of a string. In practice this should not happen (as it means
that either size is incorrect or that dst is not a proper ''C'' string).
The check exists to prevent potential security problems in incorrect code.*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;
	size_t		max;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	max = size - dst_len - 1;
	if (size > 0 && dst[size - 1] == '\0')
	{
		while (i < max && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		if (i < size)
			dst[dst_len + i] = '\0';
		else
			return (size);
		return (src_len + dst_len);
	}
	return (size);
}
