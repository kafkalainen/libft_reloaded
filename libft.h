/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:35:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/08 15:52:55 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

int			ft_atoi(char *str);

int			ft_isalpha(int c);

int			ft_isalnum(int c);

int			ft_isdigit(int c);

size_t		ft_strlen(const char *s);

char		*ft_strdup(char *src);

char		*ft_strcat(char *dest, const char *src);

int			ft_strcmp(const char *s1, const char *s2);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *str, int c);

char		*ft_strncat(char *dest, const char *src, size_t n);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strcpy(char *dest, const char *src);

char		*ft_strncpy(char *dest, const char *src, size_t n);

char		*ft_strstr(const char *haystack, const char *needle);

char		*ft_strnstr(const char *big, const char *little, size_t len);

#endif
