/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:35:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/04 15:26:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

int			ft_strlen(char *str);

char		*ft_strdup(char *src);

int			ft_strcmp(const char *s1, const char *s2);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strcpy(char *dest, const char *src);

int			ft_atoi(char *str);
#endif
