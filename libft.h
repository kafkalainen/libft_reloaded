/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:35:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/12 15:01:51 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

int			ft_atoi(char *str);

void		ft_bzero(void *s, size_t n);

int			ft_isalpha(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isdigit(int c);

int			ft_isprint(int c);

void		*ft_memalloc(size_t size);

void		*ft_memset(void *s, int c, size_t n);

void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memcpy(void *dest, const void *src, size_t n);

void		ft_memdel(void **ap);

void		*ft_memmove(void *dest, const void *src, size_t n);

void		ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(char const *s, int fd);

void		ft_putstr_fd(char const *s, int fd);

size_t		ft_strlen(const char *s);

char		*ft_strdup(char *src);

char		*ft_strcat(char *dest, const char *src);

int			ft_strcmp(const char *s1, const char *s2);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *str, int c);

char		*ft_strncat(char *dest, const char *src, size_t n);

void		ft_strclr(char *s);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strcpy(char *dest, const char *src);

void		ft_striter(char *s, void (*f)(char *));

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_strncpy(char *dest, const char *src, size_t n);

void		ft_strdel(char **as);

int			ft_strequ(char const *s1, char const *s2);

int			ft_strnequ(char const *s1, char const *s2, size_t n);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strmap(char const *s, char (*f)(char));

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strnew(size_t size);

char		*ft_strstr(const char *haystack, const char *needle);

char		*ft_strnstr(const char *big, const char *little, size_t len);

char		*ft_strsub(char const *s, unsigned int start, size_t len);

char		*ft_strtrim(char const *s);

int			ft_toupper(int c);

int			ft_tolower(int c);
#endif
