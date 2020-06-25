/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:42:20 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/25 17:05:16 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <bsd/string.h>

void	yellow(void) {
  printf("\033[1;33m");
}

void	green(void) {
  printf("\033[1;32m");
}

void	red(void) {
  printf("\033[1;31m");
}

void	ft_default(void) {
	printf("\033[0m");
}


void	ft_main_strdel(char **as)
{
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_main_strarrdel(char **as, size_t	size)
{
	size_t		i;

	i = 0;
	if (as != NULL)
	{
		while (i < size)
		{
			ft_main_strdel(&as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
}

void ft_memory_function_tester(void *own, void *system, size_t siz)
{
	if (own == NULL && system == NULL)
	{
		printf("\033[1;32m");
		printf("both NULL: OK\n");
		printf("\033[0m");
	}
	else
	{
		if (memcmp(own, system, siz) == 0)
		{
			printf("\033[1;32m");
			printf("strcmp after char* cast: OK\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[1;31m");
			printf("\033[0m");
		}
	}
}

void ft_string_function_tester(char *own, char *system)
{
	if (own == NULL && system == NULL)
	{
		printf("\033[1;32m");
		printf("strcmp: both null: OK\n");
		printf("\033[0m");
	}
	else
	{
		if (strcmp(own, system) == 0)
		{
			printf("\033[1;32m");
			printf("strcmp: OK\n");
			/*printf("own: %s\nsystem: %s\n", own, system);*/
			printf("\033[0m");
		}
		else
		{
			printf("\033[1;31m");
			printf("strcmp: KO\n");
			/*printf("own: %s\nsystem: %s\n", own, system);*/
			printf("\033[0m");
		}
	}
}

void ft_long_int_function_tester(size_t own, size_t system)
{
	if (own == system)
	{
		printf("\033[1;32m");
		printf("diff: OK\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\nown: %ld\nsystem: %ld\n", own, system);
		printf("\033[0m");
	}
}

void ft_int_function_tester(int own, int system)
{
	if (own == system)
	{
		printf("\033[1;32m");
		printf("diff: OK\n");
		/*printf("own: %d\nsystem: %d\n", own, system);*/
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\n");
		printf("own: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
}

void ft_cmp_function_tester(int own, int system)
{
	if (own < 0 && system < 0)
	{
		printf("\033[1;32m");
		printf("cmp returns both negative: OK\nown: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
	else if (own > 0 && system > 0)
	{
		printf("\033[1;32m");
		printf("cmp returns both positive: OK\nown: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
	else if (own == 0 && system == 0)
	{
		printf("\033[1;32m");
		printf("cmp returns both 0: OK\nown: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\nown: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
}

void ft_memchr_tester()
{
	char *test;

	test = (char*)malloc(sizeof(*test) * 15);
	strcpy(test, "Hello it's me.");
	printf("ft_memchr: searches mem for char c and returns a pointer to where first instance is found.\n");
	ft_memory_function_tester(ft_memchr(test, 'r', 14), memchr(test, 'r', 14), 15);
	ft_memory_function_tester(ft_memchr(test, '.', 14), memchr(test, '.', 14), 1);
	ft_memory_function_tester(ft_memchr(test, 'o', 20), memchr(test, 'o', 20), 11);
	free(test);
}

void ft_memmove_tester()
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *test;

	yellow();
	printf("ft_memmove: moves a src to a temp and copies temp to dest and returns a pointer to dest.\n");
	str = (char*)malloc(sizeof(*str) * 20);
	str2 = (char*)malloc(sizeof(*str2) * 10);
	str3 = (char*)malloc(sizeof(*str3) * 20);
	str4 = (char*)malloc(sizeof(*str4) * 10);
	test = (char*)malloc(sizeof(*test) * 14);
	memcpy(str, "Hello I am original", 20);
	memcpy(str2, "Yes I am", 9);
	memcpy(str3, "Hello I am original", 20);
	memcpy(str4, "Yes I am", 9);
	memcpy(test, "No you're not", 14);
	ft_memmove(str, test, 14);
	ft_memmove(str2, str2 + 5, 4);
	memmove(str3, test, 14);
	memmove(str4, str4 + 5, 4);
	ft_string_function_tester(str, str3);
	ft_string_function_tester(str2, str4);
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(test);
}

void	ft_memcmp_tester(char *s2, char *s1)
{
	char **str;
	int tab1[100];
	int tab2[100];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		tab1[i] = i;
		tab2[i] = i;
		i++;
	}
	tab2[41] = 42;
	str = (char**)malloc(sizeof(*str) * 5);
	while (j < 4)
	{
		str[j] = (char*)malloc(sizeof(*str) * 15);
		ft_strcpy(str[j], "Hello it's me.");
		j++;
	}
	str[j] = '\0';
	str[2][6] = 'a';
	str[3][6] = 'z';
	yellow();
	printf("ft_memcmp: compares mem spaces until n byte.\n");
	ft_default();
	printf("Comparison of tab1 and tab2 with size 100:\n");
	i = ft_memcmp(tab2, tab1, sizeof(tab1));
	j = memcmp(tab2, tab1, sizeof(tab1));
	ft_cmp_function_tester(i, j);
	printf("Comparison of equal with size 15:\n");
	i = ft_memcmp(str[0], str[1], 15);
	j = memcmp(str[0], str[1], 15);
	ft_cmp_function_tester(i, j);
	printf("Comparison of bigger with size 15:\n");
	i = ft_memcmp(str[0], str[2], 15);
	j = memcmp(str[0], str[2], 15);
	ft_cmp_function_tester(i, j);
	printf("Comparison of smaller with size 15:\n");
	i = ft_memcmp(str[0], str[3], 15);
	j = memcmp(str[0], str[3], 15);
	ft_cmp_function_tester(i, j);
	printf("Comparison with size of 0:\n");
	i = ft_memcmp(str[0], str[3], 0);
	j = memcmp(str[0], str[3], 0);
	ft_cmp_function_tester(i, j);
	printf("Comparison, where size is way over what it should:\n");
	i = ft_memcmp(str[0], str[3], 200);
	j = memcmp(str[0], str[3], 200);
	ft_cmp_function_tester(i, j);
	if (ft_strlen(s1) > ft_strlen(s2))
	{
		i = ft_memcmp(s1, s2, ft_strlen(s2));
		j = memcmp(s1, s2, ft_strlen(s2));
		ft_cmp_function_tester(i, j);
	}
	else
	{
		i = ft_memcmp(s1, s2, ft_strlen(s1));
		j = memcmp(s1, s2, ft_strlen(s1));
		ft_cmp_function_tester(i, j);
	}
	free(str[0]);
	str[0] = NULL;
	free(str[1]);
	str[1] = NULL;
	free(str[2]);
	str[2] = NULL;
	free(str[3]);
	str[3] = NULL;
	free(str[4]);
	str[4] = NULL;
	free(str);
	str = NULL;
}

void	ft_strcat_tester(char *s1, char *s2)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char str5[11];
	char str6[6];
	char str7[11];
	char str8[6];

	str1 = (char*)malloc(sizeof(*str1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (ft_strlen(s2) + 1));
	str3 = (char*)malloc(sizeof(*str3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	str4 = (char*)malloc(sizeof(*str4) * (ft_strlen(s2) + 1));
	yellow();
	printf("ft_strcat: Copied first string to end of an another string. Results were: \n");
	ft_default();
	printf("Testing catenation with parameters:\n");
	strcpy(str1, s1);
	strcpy(str2, s2);
	strcpy(str3, s1);
	strcpy(str4, s2);
	ft_string_function_tester(ft_strcat(str1, str2), strcat(str3, str4));
	printf("Testing catenation with fixed length parameters with enough space:\n");
	strcpy(str5, "Hello");
	strcpy(str6, "Hullo");
	strcpy(str7, "Hello");
	strcpy(str8, "Hullo");
	ft_string_function_tester(ft_strcat(str5, str6), strcat(str7, str8));
	/*printf("Testing catenation with no space in the end:\n");
	strcpy(str9, "Thisistoo");
	strcpy(str10, "longforyu");
	ft_string_function_tester(ft_strcat(str9, str10), strcat(str9, str10));*/
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

void	ft_strncat_tester(char *s1, char *s2)
{
	int		i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(*str) * 5);
	while (i < 2)
	{
		str[i] = (char*)malloc(sizeof(*str) * (strlen(s1) + strlen(s2) / 2 + 1));
		i++;
	}
	while (i < 4)
	{
		str[i] = (char*)malloc(sizeof(*str) * (strlen(s2) + 1));
		i++;
	}
	str[i] = '\0';
	yellow();
	printf("ft_strncat: Copied half of characters of par 2 to par 1. Results were: \n");
	ft_default();
	printf("Testing catenation with parameters:\n");
	strcpy(str[0], s1);
	strcpy(str[1], s1);
	strcpy(str[2], s2);
	strcpy(str[3], s2);
	ft_string_function_tester(ft_strncat(str[0], str[2], strlen(s2) / 2), strncat(str[1], str[3], strlen(s2) / 2));
	i = 0;
	while (i < 5)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_strlcat_tester(char *s1, char *s2)
{
	char *str1;
	char *str2;
	char *str11;
	char *str12;
	char *str5;
	char *str6;
	char *str15;
	char *str16;
	char str7[10];
	char str8[10];
	char str17[10];
	char str18[10];
	char str9[10];
	char str10[10];
	char str19[10];
	char str20[10];

	str1 = (char*)malloc(sizeof(*str1) * (strlen(s1) + strlen(s2) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (strlen(s2) + 1));
	str5 = (char*)malloc(sizeof(*str5) * (strlen(s1) + strlen(s2) + 1));
	str6 = (char*)malloc(sizeof(*str6) * (strlen(s2) + 1));
	str11 = (char*)malloc(sizeof(*str11) * (strlen(s1) + strlen(s2) + 1));
	str12 = (char*)malloc(sizeof(*str12) * (strlen(s2) + 1));
	str15 = (char*)malloc(sizeof(*str15) * (strlen(s1) + strlen(s2) + 1));
	str16 = (char*)malloc(sizeof(*str16) * (strlen(s2) + 1));

	yellow();
	printf("Test ft_strlcat: Copied first string to end of an another string. Results were: \n");
	ft_default();
	printf("Testing catenation with parameters:\n");
	strcpy(str1, s1);
	strcpy(str2, s2);
	strcpy(str5, s1);
	strcpy(str6, s2);
	strcpy(str11, s1);
	strcpy(str12, s2);
	strcpy(str15, s1);
	strcpy(str16, s2);
	printf("Testing return values:\n");
	ft_long_int_function_tester(ft_strlcat(str1, str2, sizeof(str1)), strlcat(str11, str12, sizeof(str11)));
	ft_long_int_function_tester(ft_strlcat(str5, str6, sizeof(str5)), strlcat(str15, str16, sizeof(str15)));
	printf("Testing catenated strings:\n");
	ft_string_function_tester(str1, str11);
	ft_string_function_tester(str5, str15);
	printf("Testing catenation with fixed length parameters with enough space:\n");
	strcpy(str7, "Hello");
	strcpy(str8, "Hullo");
	strcpy(str17, "Hello");
	strcpy(str18, "Hullo");
	printf("Testing return values:\n");
	ft_long_int_function_tester(ft_strlcat(str7, str8, sizeof(str7)), strlcat(str17, str18, sizeof(str17)));
	printf("Testing concatenated strings:\n");
	ft_string_function_tester(str7, str17);
	printf("Testing catenation with no space in the end:\n");
	strcpy(str9, "Thisistoo");
	strcpy(str10, "longforyu");
	strcpy(str19, "Thisistoo");
	strcpy(str20, "longforyu");
	printf("Testing return values:\n");
	ft_long_int_function_tester(ft_strlcat(str9, str10, sizeof(str9)), strlcat(str19, str20, sizeof(str19)));
	printf("Testing concatenated strings:\n");
	ft_string_function_tester(str9, str19);
	free(str1);
	free(str2);
	free(str5);
	free(str6);
	free(str11);
	free(str12);
	free(str15);
	free(str16);
}

void	ft_memalloc_tester(size_t n)
{
	void *str;
	void *str2;

	str = ft_memalloc(n);
	str2 = (void*)malloc(sizeof(*str2) * (n));
	bzero(str2, n);

	yellow();
	printf("Test ft_memalloc: Testing that there is sizeful of zeroes in the allocated memory.\n");
	ft_default();
	if (memcmp(str, str2, n) == 0)
	{
		printf("\033[1;32m");
		printf("Same amount of zeroes: OK\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\n%d\n", memcmp(str, str2, n));
		printf("\033[0m");
	}
	if (ft_memalloc(4294967295) == NULL)
		printf("OK");
	else
		printf("KO");
	free(str);
	free(str2);
}
void	ft_memdel_tester()
{
	char	*str;
	int		*tab;

	str = (char*)malloc(sizeof(*str) * (21));
	tab = (int*)malloc(sizeof(*tab) * (11));
	tab[1] = 42;
	strcpy(str, "I'm mister Meeseks.");
	yellow();
	printf("Test ft_memdel: Testing that strdel removes data from allocated memory.\n");
	ft_default();
	ft_memdel((void**)&str);
	ft_memdel((void**)&tab);
	ft_memory_function_tester(str, NULL, 8);
	ft_memory_function_tester(tab, NULL, 8);
}

void	ft_strdel_tester()
{
	char	*str;
	char	*str2;

	str = (char*)malloc(sizeof(*str) * (21));
	str2 = (char*)malloc(sizeof(*str2) * (13));
	strcpy(str, "I'm mister Meeseks.");
	strcpy(str, "Look at me!");
	yellow();
	printf("Test ft_strdel: Testing that strdel removes data from allocated memory.\n");
	ft_default();
	ft_strdel(&str);
	ft_strdel(&str2);
	ft_memory_function_tester(str, NULL, 8);
	ft_memory_function_tester(str2, NULL, 8);
}


void	ft_strclr_tester(void)
{
	char	**str;
	int		i;

	i = 0;
	str = (char**)malloc(sizeof(*str) * 4);
	while (i < 3)
	{
		str[i] = (char*)malloc(sizeof(*str) * (21));
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (i < 3)
	{
		ft_strcpy(str[i], "I'm mister Meeseks.");
		i++;
	}
	yellow();
	printf("Test ft_strclr: Tests with three strings that are null terminated that there are just nulls.\n");
	ft_default();
	ft_strclr(str[0]);
	ft_strclr(str[1]);
	ft_strclr(str[2]);
	ft_string_function_tester(str[0], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	ft_string_function_tester(str[1], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	ft_string_function_tester(str[2], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	ft_main_strdel(&str[0]);
	ft_main_strdel(&str[1]);
	ft_main_strdel(&str[2]);
	ft_main_strdel(&str[3]);
	free(str);
	str = NULL;
}

void	ft_strnew_tester(size_t n)
{
	void *str;
	void *str2;

	str = ft_strnew(n);
	str2 = (char*)malloc(sizeof(*str2) * (n + 1));
	bzero(str2, n + 1);
	yellow();
	printf("Test ft_strnew: Testing that there is sizeful of zeroes in the allocated memory.\n");
	ft_default();
	if (memcmp(str, str2, n) == 0)
	{
		printf("\033[1;32m");
		printf("Same amount of zeroes: OK\n");
		ft_default();
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\n%d\n", memcmp(str, str2, n));
		ft_default();
	}
	free(str);
	free(str2);
}

void	ft_puts(char *s)
{
	write(1, s, strlen(s));
}

char	ft_toupper_char(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

char	ft_rot_char(unsigned int i, char c)
{
	if (i == 0)
	{
		return (c - 32);
	}
	else
		return (c);
}

void	ft_rot2_char(unsigned int i, char *c)
{
	char	d;
	if (i == 0)
	{
		d = c[i] - 32;
		write(1, &d, 1);
	}
	else
		write(1, &c[0], 1);
}

void	ft_striter_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_striter: Testing that str_iter iterates a function.\n");
	printf("\033[0m");
	printf(":\n");
	ft_striter(s1, ft_puts);
	ft_putchar_fd('\n', 1);
	ft_striter(s2, ft_puts);
	ft_putchar_fd('\n', 1);
	ft_striter("Hello", ft_puts);
	ft_putchar_fd('\n', 1);
}

void	ft_striteri_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_striteri: Testing that str_iteri iterates a function.\n");
	printf("\033[0m");
	printf(":\n");
	ft_striteri(s1, ft_rot2_char);
	ft_putchar_fd('\n', 1);
	ft_striteri(s2, ft_rot2_char);
	ft_putchar_fd('\n', 1);
}

void	ft_putcha_test(char *s1, char *s2)
{
	yellow();
	printf("Test ft_putchar_fd: Testing that ft_putchar puts out a character.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putchar_fd(s1[0], 1);
	ft_putchar_fd(s2[0], 1);
	yellow();
	printf("Test ft_putstr_fd: Testing that ft_putstr puts out a string.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putstr_fd(s1, 1);
	ft_putstr_fd(s2, 1);
	ft_putchar_fd('\n', 1);
	yellow();
	printf("Test ft_putendl_fd: Testing that ft_puendl puts out a string with nl to 2 fd.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd(s1, 2);
	ft_putendl_fd(s2, 2);
}

void	ft_strmap_test()
{

	char *s1_old;
	char *s2_old;
	char *s1_new;
	char *s2_new;

	s1_old = (char*)malloc(sizeof(*s1_new) * (17));
	s2_old = (char*)malloc(sizeof(*s2_new) * (16));
	ft_strcpy(s1_old, "i'm big capitals");
	ft_strcpy(s2_old, "big as a humwee");
	s1_new = ft_strmap(s1_old, ft_toupper_char);
	s2_new = ft_strmap(s2_old, ft_toupper_char);
	yellow();
	printf("Test ft_strmap: Testing strmap by using ft_upper char version, and cmp resulting string.\n");
	printf("\033[0m");
	ft_string_function_tester(s1_new, "I'M BIG CAPITALS");
	ft_string_function_tester(s2_new, "BIG AS A HUMWEE");
	free(s1_old);
	free(s2_old);
	free(s1_new);
	free(s2_new);
}

void	ft_strmapi_test()
{

	char *s1_old;
	char *s2_old;
	char *s1_new;
	char *s2_new;

	s1_old = (char*)malloc(sizeof(*s1_new) * (17));
	s2_old = (char*)malloc(sizeof(*s2_new) * (16));
	ft_strcpy(s1_old, "i'm big capitals");
	ft_strcpy(s2_old, "big as a humwee");
	s1_new = ft_strmapi(s1_old, ft_rot_char);
	s2_new = ft_strmapi(s2_old, ft_rot_char);
	yellow();
	printf("Test ft_strmapi: Testing strmap by using ft_upper char version, and cmp resulting string.\n");
	printf("\033[0m");
	ft_string_function_tester(s1_new, "I'm big capitals");
	ft_string_function_tester(s2_new, "Big as a humwee");
	free(s1_old);
	free(s2_old);
	free(s1_new);
	free(s2_new);
}

void	ft_strequ_tester()
{
	yellow();
	printf("Test ft_strequ: Testing by giving it string literals\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with strings Hello and Hello.", 1);
	ft_int_function_tester(ft_strequ("Hello", "Hello"), 1);
	printf("<\n");
	ft_putendl_fd("test with strings Hello and ello.", 1);
	ft_int_function_tester(ft_strequ("Hello", "ello"), 0);
	printf("<\n");
	ft_putendl_fd("test with strings Hello and Jello.", 1);
	ft_int_function_tester(ft_strequ("Hello", "Jello"), 0);
	printf("<\n");
}

void	ft_strnequ_tester()
{
	yellow();
	printf("Test ft_strnequ: Testing by giving it string literals.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with strings Hello and Hello for three characters.", 1);
	ft_int_function_tester(ft_strnequ("Hello", "Hello", 3), 1);
	printf("<\n");
	ft_putendl_fd("test with strings Hello and ello with one character.", 1);
	ft_int_function_tester(ft_strnequ("Hello", "ello", 1), 0);
	printf("<\n");
	ft_putendl_fd("test with strings elloH and elloJ with four characters.", 1);
	ft_int_function_tester(ft_strnequ("elloH", "elloJ", 4), 1);
	printf("<\n");
}

void	ft_strsub_tester()
{
	char str[31];
	char str2[13];

	strcpy(str, "Cut off this part Hello World!");
	strcpy(str2, "Hello World!");
	yellow();
	printf("Test ft_strsub: Testing by giving it string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with 'Cut off this part Hello World!'.", 1);
	ft_string_function_tester(ft_strsub(str, 18, 12), str2);
	printf(":\n");
}

void	ft_strjoin_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_strjoin: Testing it by giving it two string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with 'Hello' and 'Hello'.", 1);
	ft_string_function_tester(ft_strjoin("Hello", "Hello"), "HelloHello");
	printf("<\n");
	ft_putendl_fd("test with parameters.", 1);
	ft_putendl_fd(ft_strjoin(s1, s2), 1);
}

void	ft_strtrim_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_strtrim: Testing it by giving it few string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with '    Hello     ' and '     Hel    lo     '.", 1);
	ft_string_function_tester(ft_strtrim("    Hello     "), "Hello");
	ft_string_function_tester(ft_strtrim("     Hel    lo     "), "Hel    lo");
	printf("<\n");
	ft_putendl_fd("test with parameters.", 1);
	ft_putendl_fd(ft_strjoin(s1, s2), 1);
}

void	ft_strsplit_tester()
{
	char **arr_str0;
	char **arr_str1;
	char **arr_str2;
	char **arr_str3;

	arr_str0 = ft_strsplit("     Marvin    rules     ", ' ');
	arr_str1 = ft_strsplit("     Coffee  breaks are for weak.", ' ');
	arr_str2 = ft_strsplit("%%%%%%Galaxy is%%%%for%%%%all.", '%');
	arr_str3 = ft_strsplit("%%%%%%%%%%%%%%%%%%%%%%%%", '%');
	yellow();
	printf("Test ft_strsplit: Testing it by giving it few string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_string_function_tester(arr_str0[0], "Marvin");
	ft_string_function_tester(arr_str0[1], "rules");
	ft_string_function_tester(arr_str0[2], NULL);
	ft_string_function_tester(arr_str1[1], "breaks");
	ft_string_function_tester(arr_str2[0], "Galaxy is");
	ft_string_function_tester(arr_str3[0], NULL);
	ft_main_strarrdel(arr_str0, 3);
	ft_main_strarrdel(arr_str1, 6);
	ft_main_strarrdel(arr_str2, 4);
	ft_main_strarrdel(arr_str3, 1);
}

void	ft_itoa_tester()
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = ft_itoa(12345);
	str2 = ft_itoa(-12345);
	str3 = ft_itoa(-2147483648);
	str4 = ft_itoa(123456000);
	yellow();
	printf("Test ft_itoa: Testing it by giving it few integrals and printf:ing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with '12345' and '-12345'.", 1);
	ft_string_function_tester(str1, "12345");
	ft_string_function_tester(str2, "-12345");
	ft_string_function_tester(str3, "-2147483648");
	ft_string_function_tester(str4, "123456000");
	ft_main_strdel(&str1);
	ft_main_strdel(&str2);
	ft_main_strdel(&str3);
	ft_main_strdel(&str4);
	printf("<\n");
}

void	ft_putcha_test2(char *s1, char *s2)
{
	yellow();
	printf("Test ft_putchar_fd: Testing that ft_putchar puts out a character.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putchar(s1[0]);
	ft_putchar(s2[0]);
	yellow();
	printf("Test ft_putstr_fd: Testing that ft_putstr puts out a string.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putchar('\n');
	yellow();
	printf("Test ft_putendl_fd: Testing that ft_putendl puts out a string with nl to 2 fd.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putendl(s1);
	ft_putendl(s2);
}

void	ft_putnbr_test()
{
	yellow();
	printf("Test ft_putnbr: Testing that ft_putnbr puts out a integer.\n");
	printf("\033[0m");
	printf("Test with max integers\n");
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(-42);
	ft_putchar('\n');
}

void	ft_putnbr_fd_test()
{
	yellow();
	printf("Test ft_putnbr_fd: Testing that ft_putnbr_fd puts out a integer in correct file descriptor.\n");
	printf("\033[0m");
	printf("Test with max integers\n");
	ft_putnbr_fd(-2147483648, 2);
	ft_putchar('\n');
	ft_putnbr_fd(2147483647, 2);
	ft_putchar('\n');
	ft_putnbr_fd(42, 2);
	ft_putchar('\n');
	ft_putnbr_fd(-42, 2);
	ft_putchar('\n');
}

void	ft_memset_test()
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = (char*)malloc(sizeof(*str1) * 15);
	str2 = (char*)malloc(sizeof(*str2) * 15);
	str3 = (char*)malloc(sizeof(*str3) * 15);
	str4 = (char*)malloc(sizeof(*str4) * 15);

	strcpy(str1,"Hello it's me.");
	strcpy(str2,"Hello it's me.");
	strcpy(str3,"Hello it's me.");
	strcpy(str4,"Hello it's me.");
	printf("ft_memset: fills the first n bytes with constant byte c. Returns pointer.\n");
	ft_memory_function_tester(ft_memset(str1, '$', 5), memset(str2, '$', 5), 15);
	ft_memory_function_tester(ft_memset(str3, '$', 15), memset(str4, '$', 15), 15);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

void	ft_bzero_test()
{
	char *str;
	char *str2;

	str = (char*)malloc(sizeof(*str) * 7);
	str2 = (char*)malloc(sizeof(*str2) * 7);
	yellow();
	printf("ft_bzero: removes memory area by writing zeroes to the given area.\n");
	printf("\033[0m");
	strcpy(str, "Hello.");
	strcpy(str2, "Hello.");
	ft_bzero(str, 7);
	bzero(str2, 7);
	ft_memory_function_tester(str, str2, 7);
	free(str);
	free(str2);
}

void	ft_memcpy_test()
{

	char *str;
	char *str2;

	str = (char*)malloc(sizeof(*str) * 7);
	str2 = (char*)malloc(sizeof(*str2) * 7);
	yellow();
	printf("ft_memcpy: copies n bytes from src to dest. Returns a pointer to dest.\n");
	printf("\033[0m");
	ft_memory_function_tester(ft_memcpy(str, "hello", 7), memcpy(str2, "hello", 7), 7);
	free(str);
	free(str2);
}

void	ft_memccpy_test()
{

	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *cpstr;

	str = (char*)malloc(sizeof(*str) * 30);
	str2 = (char*)malloc(sizeof(*str2) * 30);
	str3 = (char*)malloc(sizeof(*str3) * 12);
	str4 = (char*)malloc(sizeof(*str4) * 12);
	cpstr = (char*)malloc(sizeof(*cpstr) * 30);
	strcpy(str3, "laaelectric");
	strcpy(str4, "laaelectric");
	strcpy(cpstr, "This is a string: not copied.");
	yellow();
	printf("ft_memccpy: copies n bytes from src to dest. Returns a pointer to dest + i if c is found.\n");
	printf("\033[0m");
	ft_memccpy(str, cpstr, ':', 30);
	memccpy(str2,  cpstr, ':', 30);
	ft_memory_function_tester(str, str2, 15);
	free(str);
	free(str2);
	ft_putendl("If electric is printed, first part of the string was correctly copied.");
	ft_memory_function_tester(ft_memccpy(str3, "eel", 'l', 3), memccpy(str4, "eel", 'l', 3), 9);
	free(str3);
	free(str4);
	free(cpstr);
}

void	ft_strlen_test(char *s1, char *s2)
{
	size_t		i;
	size_t		j;

	yellow();
	printf("ft_strlen: calculate length of the string and compare to system function.\n");
	printf("\033[0m");
	i = ft_strlen(s1);
	j = strlen(s1);
	ft_long_int_function_tester(i, j);
	i = ft_strlen(s2);
	j = strlen(s2);
	ft_long_int_function_tester(i, j);
}

void	ft_strdup_test(char *s1, char *s2)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;

	yellow();
	printf("ft_strdup: returns a pointer to a new string which is duplicate of given params.\n");
	printf("\033[0m");
	str = strdup(s1);
	str3 = ft_strdup(s1);
	str2 = strdup(s2);
	str4 = ft_strdup(s2);
	ft_string_function_tester(str, str3);
	ft_string_function_tester(str2, str4);
	free(str);
	free(str2);
	free(str3);
	free(str4);
}

void	ft_strcpy_test(char *s1, char *s2)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (ft_strlen(s2) + 1));
	str3 = (char*)malloc(sizeof(*str3) * (ft_strlen(s1) + 1));
	str4 = (char*)malloc(sizeof(*str4) * (ft_strlen(s2) + 1));
	yellow();
	printf("ft_strcpy: copies a str to dst.\n");
	printf("\033[0m");
	strcpy(str, s1);
	ft_strcpy(str3, s1);
	strcpy(str2, s2);
	ft_strcpy(str4, s2);
	ft_string_function_tester(str, str3);
	ft_string_function_tester(str2, str4);
	free(str);
	free(str2);
	free(str3);
	free(str4);
}

void	ft_strncpy_test(char *s1, char *s2)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s2) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (ft_strlen(s2) + 1));
	str3 = (char*)malloc(sizeof(*str3) * (ft_strlen(s2) + 1));
	str4 = (char*)malloc(sizeof(*str4) * (ft_strlen(s2) + 1));
	yellow();
	printf("ft_strncpy: copies params str to dst until nth byte.\n");
	printf("\033[0m");
	strncpy(str, s1, ft_strlen(s2));
	ft_strncpy(str3, s1, ft_strlen(s2));
	strncpy(str2, s2, ft_strlen(s2) / 2);
	ft_strncpy(str4, s2, ft_strlen(s2) / 2);
	ft_cmp_function_tester(ft_memcmp(str, str3, ft_strlen(s2)), 0);
	ft_cmp_function_tester(ft_memcmp(str4, str2, ft_strlen(s2) / 2), 0);
	free(str);
	free(str2);
	free(str3);
	free(str4);
}

void	ft_strchr_test(char *s1, char *s2)
{
	yellow();
	printf("ft_strchr: Returns pointer to first occurance in a string and using first letter. Results were: \n");
	ft_default();
	ft_string_function_tester(ft_strchr(s1, s2[0]), strchr(s1, s2[0]));
	printf("Test if it accounts null character as well.\n");
	ft_string_function_tester(ft_strchr(s1, '\0'), strchr(s1, '\0'));
	printf("And test if it returns null when it is not found.\n");
	ft_string_function_tester(ft_strchr("Not found", 'z'), strchr("Not found", 'z'));
}


void	ft_strrchr_test(char *s1, char *s2)
{
	yellow();
	printf("ft_strrchr: Returns pointer to the last occurance in a string and using first letter. Results were: \n");
	ft_default();
	ft_string_function_tester(ft_strrchr(s1, s2[0]), strrchr(s1, s2[0]));
	printf("Test if it accounts null character as well.\n");
	ft_string_function_tester(ft_strrchr(s1, '\0'), strrchr(s1, '\0'));
	printf("And test if it returns null when it is not found.\n");
	ft_string_function_tester(ft_strrchr("Not found", 'z'), strrchr("Not found", 'z'));
}

void	ft_strstr_test(char *s1, char *s2)
{
	/*char str[3];

	strncpy(str, "hey", 3);*/
	yellow();
	printf("ft_strstr: Returns pointer to the first occurance of a substring and using substring. Results were: \n");
	ft_default();
	ft_string_function_tester(ft_strstr(s1, s2), strstr(s1, s2));
	printf("Original string was: %s\n", s1);
	printf("Test if returns null when it is not found.\n");
	ft_string_function_tester(ft_strstr("NOt gonne find me", "Hello"), strstr("NOt gonne find me", "Hello"));
	ft_string_function_tester(ft_strstr("Terminatorr", "Terminator"), strstr("Terminatorr", "Terminator"));
	printf("Following test needs to be run without -Wall -Wextra -Werror flag to test that it does not cmp null terminators.\n");
	/*ft_string_function_tester(ft_strstr("hey", str), strstr("hey", str));*/
}

void	ft_strnstr_tester(char *big, char *little)
{
	yellow();
	printf("Test ft_strnstr: Testing that substring can be found.\n");
	ft_default();
	printf("Testing with a string with limited length, answer is behind\n");
	ft_string_function_tester(ft_strnstr("Can't find me", "me", 11), strnstr("Can't find me", "me", 11));
	printf("search using a first string of par with limited length of 5\n");
	printf("both functions make a segfault if parameter is too short: aaanaa naa\n");
	ft_string_function_tester(ft_strnstr(big, little, ft_strlen(little)), strnstr(big, little, ft_strlen(little)));
	printf("search using a first string of par with empty string of limited length of 5\n");
	ft_string_function_tester(ft_strnstr(big, "", 5), strnstr(big, "", 5));
	printf("search using a first string of par with null string of limited length of 5\n");
	printf("segfault tester: uncomment to test\n");
	/*ft_string_function_tester(ft_strnstr(big, NULL, n), strnstr(big, NULL, n));*/
	printf("Testing with a string with limited length, answer is behind null terminator\n");
	ft_string_function_tester(ft_strnstr("Can't\0me find", "me", 11), strnstr("Can't\0me find", "me", 11));
	printf("Testing with a string with limited length, answer is found\n");
	ft_string_function_tester(ft_strnstr("Can't me find", "me", 11), strnstr("Can't me find", "me", 11));
}

void	ft_strcmp_test(char *s1, char *s2)
{
	char *str;
	char *str2;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (ft_strlen(s2) + 1));
	strcpy(str, s1);
	strcpy(str2, s2);
	yellow();
	printf("ft_strcmp: Compared two strings. Result was: \n");
	printf("\033[0m");
	ft_cmp_function_tester(ft_strcmp(s1, str), strcmp(s1, str));
	ft_cmp_function_tester(ft_strcmp(s2, str2), strcmp(s2, str2));
	ft_cmp_function_tester(ft_strcmp("", ""), strcmp("", ""));
	ft_cmp_function_tester(ft_strcmp("\212", "\0"), strcmp("\212", "\0"));
	ft_cmp_function_tester(ft_strcmp("a", "abc"), strcmp("a", "abc"));
	yellow();
	printf("ft_strncmp: Compared two params until half of the length of param. Result was: \n");
	printf("\033[0m");
	ft_cmp_function_tester(ft_strncmp(s1, str, ft_strlen(str) / 2), strncmp(s1, str, ft_strlen(str) / 2));
	ft_cmp_function_tester(ft_strncmp(s2, str2, ft_strlen(str2) / 2), strncmp(s2, str2, ft_strlen(str) / 2));
	ft_cmp_function_tester(ft_strncmp("\212", "\0", 1), strncmp("\212", "\0", 1));
	ft_cmp_function_tester(ft_strncmp("abc", "abcde", 3), strncmp("abc", "abcde", 3));
	ft_cmp_function_tester(ft_strncmp("abc", "abc\0de", 30), strncmp("abc", "abc\0de", 30));
	ft_cmp_function_tester(ft_strncmp("abc", "abb\0de", 30), strncmp("abc", "abb\0de", 30));
	ft_cmp_function_tester(ft_strncmp("4", "2", 0), strncmp("4", "2", 0));
	ft_main_strdel(&str);
	ft_main_strdel(&str2);
}

void	ft_atoi_test(char *s1, char *s2)
{
	yellow();
	printf("ft_atoi: Stripped strings to an integer. Results were: \n");
	ft_default();
	ft_int_function_tester(ft_atoi(s1), atoi(s2));
	ft_int_function_tester(ft_atoi(s1), atoi(s2));
	ft_int_function_tester(ft_atoi("38713813138aaaa"), atoi("38713813138aaaa"));
	ft_int_function_tester(ft_atoi("-387138aaaa"), atoi("-387138aaaa"));
	ft_int_function_tester(ft_atoi("aaa22"), atoi("aaa22"));
	ft_int_function_tester(ft_atoi("- 42"), atoi("- 42"));
	ft_int_function_tester(ft_atoi("+42"), atoi("+42"));
	ft_int_function_tester(ft_atoi("++42"), atoi("++42"));
	ft_int_function_tester(ft_atoi(" -sasdadsf"), atoi(" -sasdadsf"));
	ft_int_function_tester(ft_atoi(""), atoi(""));
	ft_int_function_tester(ft_atoi("+007"), atoi("+007"));
	ft_int_function_tester(ft_atoi("--66"), atoi("--66"));
	ft_int_function_tester(ft_atoi("-42"), atoi("-42"));
	ft_int_function_tester(ft_atoi("--42"), atoi("--42"));
	ft_int_function_tester(ft_atoi("0120223"), atoi("0120223"));
	ft_int_function_tester(ft_atoi("000000000000000110"), atoi("000000000000000110"));
	ft_int_function_tester(ft_atoi(" 1"), atoi(" 1"));
	ft_int_function_tester(ft_atoi(" 21 "), atoi(" 21 "));
	ft_int_function_tester(ft_atoi("42jk "), atoi("42jk "));
	ft_int_function_tester(ft_atoi("\n42"), atoi("\n42"));
	ft_int_function_tester(ft_atoi("1-2"), atoi("1-2"));
	ft_int_function_tester(ft_atoi("4+2"), atoi("4+2"));
	ft_int_function_tester(ft_atoi("  +42"), atoi("  +42"));
	ft_int_function_tester(ft_atoi("  -42"), atoi("  -42"));
	ft_int_function_tester(ft_atoi("4,5"), atoi("4,5"));
	ft_int_function_tester(ft_atoi("+"), atoi("+"));
	ft_int_function_tester(ft_atoi("-"), atoi("-"));
	ft_int_function_tester(ft_atoi("-+1"), atoi("-+1"));
	ft_int_function_tester(ft_atoi("+-1"), atoi("+-1"));
	ft_int_function_tester(ft_atoi("\200123"), atoi("\200123"));
	ft_int_function_tester(ft_atoi("123\200"), atoi("123\200"));
	ft_int_function_tester(ft_atoi("  \t\n  \r\r\v\f-899"), atoi("  \t\n  \r\r\v\f-899"));
	ft_int_function_tester(ft_atoi("-2147483648"), atoi("-2147483648"));
	ft_int_function_tester(ft_atoi("2147483647"), atoi("2147483647"));
}

void	ft_is_test()
{
		printf("ft_isalpha: Validates that unsigned char is part of alphabet. Results were: \n");
		ft_int_function_tester(ft_isalpha((unsigned char)('0')), isalpha((unsigned char)('0')));
		ft_int_function_tester(ft_isalpha((unsigned char)('a')), isalpha((unsigned char)('a')));
		ft_int_function_tester(ft_isalpha((unsigned char)('a' + 0X100)), isalpha((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_isalpha((unsigned char)('Z')), isalpha((unsigned char)('Z')));
		ft_int_function_tester(ft_isalpha((unsigned char)('!')), isalpha((unsigned char)('!')));
		ft_int_function_tester(ft_isalpha((unsigned char)(' ')), isalpha((unsigned char)(' ')));
		ft_int_function_tester(ft_isalpha((unsigned char)(9999)), isalpha((unsigned char)(9999)));
		ft_int_function_tester(ft_isalpha((unsigned char)('\t')), isalpha((unsigned char)('\t')));
		ft_int_function_tester(ft_isalpha((unsigned char)('\n')), isalpha((unsigned char)('\n')));
		ft_int_function_tester(ft_isalpha((unsigned char)('\b')), isalpha((unsigned char)('\b')));
		ft_int_function_tester(ft_isalpha((unsigned char)('\v')), isalpha((unsigned char)('\v')));
		ft_int_function_tester(ft_isalpha((unsigned char)(0)), isalpha((unsigned char)(0)));
		ft_int_function_tester(ft_isalpha((unsigned char)(1)), isalpha((unsigned char)(1)));
		ft_int_function_tester(ft_isalpha((unsigned char)(5)), isalpha((unsigned char)(5)));
		ft_int_function_tester(ft_isalpha((unsigned char)('%')), isalpha((unsigned char)('%')));
		ft_int_function_tester(ft_isalpha((unsigned char)(-20)), isalpha((unsigned char)(-20)));
		printf("ft_isdigit: Validates that integer is part of digits. Results were: \n");
		ft_int_function_tester(ft_isdigit((unsigned char)('0')), isdigit((unsigned char)('0')));
		ft_int_function_tester(ft_isdigit((unsigned char)('a')), isdigit((unsigned char)('a')));
		ft_int_function_tester(ft_isdigit((unsigned char)('a' + 0X100)), isdigit((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_isdigit((unsigned char)('Z')), isdigit((unsigned char)('Z')));
		ft_int_function_tester(ft_isdigit((unsigned char)('!')), isdigit((unsigned char)('!')));
		ft_int_function_tester(ft_isdigit((unsigned char)(' ')), isdigit((unsigned char)(' ')));
		ft_int_function_tester(ft_isdigit((unsigned char)(9999)), isdigit((unsigned char)(9999)));
		ft_int_function_tester(ft_isdigit((unsigned char)('\t')), isdigit((unsigned char)('\t')));
		ft_int_function_tester(ft_isdigit((unsigned char)('\n')), isdigit((unsigned char)('\n')));
		ft_int_function_tester(ft_isdigit((unsigned char)('\b')), isdigit((unsigned char)('\b')));
		ft_int_function_tester(ft_isdigit((unsigned char)('\v')), isdigit((unsigned char)('\v')));
		ft_int_function_tester(ft_isdigit((unsigned char)(0)), isdigit((unsigned char)(0)));
		ft_int_function_tester(ft_isdigit((unsigned char)(1)), isdigit((unsigned char)(1)));
		ft_int_function_tester(ft_isdigit((unsigned char)(5)), isdigit((unsigned char)(5)));
		ft_int_function_tester(ft_isdigit((unsigned char)('%')), isdigit((unsigned char)('%')));
		ft_int_function_tester(ft_isdigit((unsigned char)(-20)), isdigit((unsigned char)(-20)));
		printf("ft_isalnum: Validates that tested value is part of alphabet or digits. Results were: \n");
		ft_int_function_tester(ft_isalnum((unsigned char)('0')), isalnum((unsigned char)('0')));
		ft_int_function_tester(ft_isalnum((unsigned char)('a')), isalnum((unsigned char)('a')));
		ft_int_function_tester(ft_isalnum((unsigned char)('a' + 0X100)), isalnum((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_isalnum((unsigned char)('Z')), isalnum((unsigned char)('Z')));
		ft_int_function_tester(ft_isalnum((unsigned char)('!')), isalnum((unsigned char)('!')));
		ft_int_function_tester(ft_isalnum((unsigned char)(' ')), isalnum((unsigned char)(' ')));
		ft_int_function_tester(ft_isalnum((unsigned char)(9999)), isalnum((unsigned char)(9999)));
		ft_int_function_tester(ft_isalnum((unsigned char)('\t')), isalnum((unsigned char)('\t')));
		ft_int_function_tester(ft_isalnum((unsigned char)('\n')), isalnum((unsigned char)('\n')));
		ft_int_function_tester(ft_isalnum((unsigned char)('\b')), isalnum((unsigned char)('\b')));
		ft_int_function_tester(ft_isalnum((unsigned char)('\v')), isalnum((unsigned char)('\v')));
		ft_int_function_tester(ft_isalnum((unsigned char)(0)), isalnum((unsigned char)(0)));
		ft_int_function_tester(ft_isalnum((unsigned char)(1)), isalnum((unsigned char)(1)));
		ft_int_function_tester(ft_isalnum((unsigned char)(5)), isalnum((unsigned char)(5)));
		ft_int_function_tester(ft_isalnum((unsigned char)('%')), isalnum((unsigned char)('%')));
		ft_int_function_tester(ft_isalnum((unsigned char)(-20)), isalnum((unsigned char)(-20)));
		printf("ft_isascii: Validates that tested value is an ascii character. Results were: \n");
		ft_int_function_tester(ft_isascii((unsigned char)('0')), isascii((unsigned char)('0')));
		ft_int_function_tester(ft_isascii((unsigned char)('a')), isascii((unsigned char)('a')));
		ft_int_function_tester(ft_isascii((unsigned char)('a' + 0X100)), isascii((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_isascii((unsigned char)('Z')), isascii((unsigned char)('Z')));
		ft_int_function_tester(ft_isascii((unsigned char)('!')), isascii((unsigned char)('!')));
		ft_int_function_tester(ft_isascii((unsigned char)(' ')), isascii((unsigned char)(' ')));
		ft_int_function_tester(ft_isascii((unsigned char)(9999)), isascii((unsigned char)(9999)));
		ft_int_function_tester(ft_isascii((unsigned char)('\t')), isascii((unsigned char)('\t')));
		ft_int_function_tester(ft_isascii((unsigned char)('\n')), isascii((unsigned char)('\n')));
		ft_int_function_tester(ft_isascii((unsigned char)('\b')), isascii((unsigned char)('\b')));
		ft_int_function_tester(ft_isascii((unsigned char)('\v')), isascii((unsigned char)('\v')));
		ft_int_function_tester(ft_isascii((unsigned char)(0)), isascii((unsigned char)(0)));
		ft_int_function_tester(ft_isascii((unsigned char)(1)), isascii((unsigned char)(1)));
		ft_int_function_tester(ft_isascii((unsigned char)(5)), isascii((unsigned char)(5)));
		ft_int_function_tester(ft_isascii((unsigned char)('%')), isascii((unsigned char)('%')));
		ft_int_function_tester(ft_isascii((unsigned char)(-20)), isascii((unsigned char)(-20)));
		printf("ft_isprint: Validates that tested value is a printable character. Results were: \n");
		ft_int_function_tester(ft_isprint((unsigned char)('0')), isprint((unsigned char)('0')));
		ft_int_function_tester(ft_isprint((unsigned char)('a')), isprint((unsigned char)('a')));
		ft_int_function_tester(ft_isprint((unsigned char)('a' + 0X100)), isprint((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_isprint((unsigned char)('Z')), isprint((unsigned char)('Z')));
		ft_int_function_tester(ft_isprint((unsigned char)('!')), isprint((unsigned char)('!')));
		ft_int_function_tester(ft_isprint((unsigned char)(' ')), isprint((unsigned char)(' ')));
		ft_int_function_tester(ft_isprint((unsigned char)(9999)), isprint((unsigned char)(9999)));
		ft_int_function_tester(ft_isprint((unsigned char)('\t')), isprint((unsigned char)('\t')));
		ft_int_function_tester(ft_isprint((unsigned char)('\n')), isprint((unsigned char)('\n')));
		ft_int_function_tester(ft_isprint((unsigned char)('\b')), isprint((unsigned char)('\b')));
		ft_int_function_tester(ft_isprint((unsigned char)('\v')), isprint((unsigned char)('\v')));
		ft_int_function_tester(ft_isprint((unsigned char)(0)), isprint((unsigned char)(0)));
		ft_int_function_tester(ft_isprint((unsigned char)(1)), isprint((unsigned char)(1)));
		ft_int_function_tester(ft_isprint((unsigned char)(5)), isprint((unsigned char)(5)));
		ft_int_function_tester(ft_isprint((unsigned char)('%')), isprint((unsigned char)('%')));
		ft_int_function_tester(ft_isprint((unsigned char)(-20)), isprint((unsigned char)(-20)));
		printf("ft_toupper: Changes char to uppercase: \n");
		ft_int_function_tester(ft_toupper((unsigned char)('0')), toupper((unsigned char)('0')));
		ft_int_function_tester(ft_toupper((unsigned char)('a')), toupper((unsigned char)('a')));
		ft_int_function_tester(ft_toupper((unsigned char)('a' + 0X100)), toupper((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_toupper((unsigned char)('Z')), toupper((unsigned char)('Z')));
		ft_int_function_tester(ft_toupper((unsigned char)('!')), toupper((unsigned char)('!')));
		ft_int_function_tester(ft_toupper((unsigned char)(' ')), toupper((unsigned char)(' ')));
		ft_int_function_tester(ft_toupper((unsigned char)(9999)), toupper((unsigned char)(9999)));
		ft_int_function_tester(ft_toupper((unsigned char)('\t')), toupper((unsigned char)('\t')));
		ft_int_function_tester(ft_toupper((unsigned char)('\n')), toupper((unsigned char)('\n')));
		ft_int_function_tester(ft_toupper((unsigned char)('\b')), toupper((unsigned char)('\b')));
		ft_int_function_tester(ft_toupper((unsigned char)('\v')), toupper((unsigned char)('\v')));
		ft_int_function_tester(ft_toupper((unsigned char)(0)), toupper((unsigned char)(0)));
		ft_int_function_tester(ft_toupper((unsigned char)(1)), toupper((unsigned char)(1)));
		ft_int_function_tester(ft_toupper((unsigned char)(5)), toupper((unsigned char)(5)));
		ft_int_function_tester(ft_toupper((unsigned char)('%')), toupper((unsigned char)('%')));
		ft_int_function_tester(ft_toupper((unsigned char)(-20)), toupper((unsigned char)(-20)));
		printf("ft_tolower: Changes char to lowercase: \n");
		ft_int_function_tester(ft_tolower((unsigned char)('0')), tolower((unsigned char)('0')));
		ft_int_function_tester(ft_tolower((unsigned char)('a')), tolower((unsigned char)('a')));
		ft_int_function_tester(ft_tolower((unsigned char)('a' + 0X100)), tolower((unsigned char)('a' + 0X100)));
		ft_int_function_tester(ft_tolower((unsigned char)('Z')), tolower((unsigned char)('Z')));
		ft_int_function_tester(ft_tolower((unsigned char)('!')), tolower((unsigned char)('!')));
		ft_int_function_tester(ft_tolower((unsigned char)(' ')), tolower((unsigned char)(' ')));
		ft_int_function_tester(ft_tolower((unsigned char)(9999)), tolower((unsigned char)(9999)));
		ft_int_function_tester(ft_tolower((unsigned char)('\t')), tolower((unsigned char)('\t')));
		ft_int_function_tester(ft_tolower((unsigned char)('\n')), tolower((unsigned char)('\n')));
		ft_int_function_tester(ft_tolower((unsigned char)('\b')), tolower((unsigned char)('\b')));
		ft_int_function_tester(ft_tolower((unsigned char)('\v')), tolower((unsigned char)('\v')));
		ft_int_function_tester(ft_tolower((unsigned char)(0)), tolower((unsigned char)(0)));
		ft_int_function_tester(ft_tolower((unsigned char)(1)), tolower((unsigned char)(1)));
		ft_int_function_tester(ft_tolower((unsigned char)(5)), tolower((unsigned char)(5)));
		ft_int_function_tester(ft_tolower((unsigned char)('%')), tolower((unsigned char)('%')));
		ft_int_function_tester(ft_tolower((unsigned char)(-20)), tolower((unsigned char)(-20)));
}


void		ft_del_test(void *data, size_t i)
{
	if (data)
	{
		printf("%ld\n", i);
		ft_memdel(&data);
		write(1, "Del OK.\n", 8);

	}
}

void	ft_main_list_clearer(t_list **alst)
{
	t_list *item;

	while (*alst != NULL)
	{
		item = *alst;
		*alst = item->next;
		ft_del_test(item->content, item->content_size);
		free(item);
		item = NULL;
	}
}

void	ft_lstadd_test()
{
	t_list		*list;
	t_list		*second;
	char		*str;
	char		*str2;

	str = strdup("Hello Marvin.");
	str2 = strdup("You are sad..");
	yellow();
	printf("ft_lstadd: Added new element to list. Result was: \n");
	printf("\033[0m");
	list = ft_lstnew(str, sizeof(*str) * 14);
	second = ft_lstnew(str2, sizeof(*str2) * 14);
	ft_lstadd(&list, second);
	if (strcmp((char*)list->content, "You are sad..") == 0 &&
		strcmp((char*)list->next->content, "Hello Marvin.") == 0)
		printf("OK: Node added to the begin of the list.\n");
	else
		printf("KO: Node adding failed to begin %s\n", (char*)list->content);
	ft_main_list_clearer(&list);
	free(str);
	free(str2);
}

void	ft_lstnew_test()
{
	t_list		*list;
	t_list		*list2;
	char		*str;

	str = (char*)malloc(sizeof(*str) * 14);
	str = strcpy(str, "Hello Marvin.");
	list = ft_lstnew(str, sizeof(*str) * 14);
	yellow();
	printf("ft_lstnew: Added new string to list. Result was: \n");
	printf("\033[0m");
	if (strcmp((char*)(list->content), "Hello Marvin.") == 0)
		printf("OK: Content added successfully.\n");
	else
		printf("KO: Content adding failed.\n");
	list2 = ft_lstnew(NULL, 86);
	if (list2->content_size == 0)
		printf("OK: NULL pointer handled successfully.\n");
	else
		printf("KO: NULL pointer returned not null.\n");
	ft_main_list_clearer(&list);
	ft_main_list_clearer(&list2);
	free(str);
}

void		ft_lstdelone_test()
{
	t_list	*list;
	char	*str;

	yellow();
	printf("ft_lstdelone: Tested deleting one item in a list. Result was: \n");
	printf("\033[0m");
	str = strdup("hello");
	list = ft_lstnew((void*)str, sizeof(*str));
	ft_lstdelone(&list, ft_del_test);
	if (list == NULL)
		printf("OK: List is now set to NULL.\n");
	else
		printf("KO: List is not set to NULL.\n");
	free(str);
}

void		ft_mainlstadd(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void		ft_lstdel_test(void)
{
	t_list	*list;
	t_list	*second;
	t_list	*third;
	char	*str;

	yellow();
	printf("ft_lstdel: Tested deleting all items in a list. Result was: \n");
	printf("\033[0m");
	str = strdup("hello");
	list = ft_lstnew(str, sizeof(*str));
	second = ft_lstnew(str, sizeof(*str));
	third = ft_lstnew(str, sizeof(*str));
	ft_mainlstadd(&list, second);
	ft_mainlstadd(&list, third);
	ft_lstdel(&list, ft_del_test);
	if (list == NULL)
		printf("OK: List is now set to NULL.\n");
	else
		printf("KO: List is not set to NULL.\n");
	free(str);
}

void	ft_lstiter_function(t_list *elem)
{
	t_list	*temp;

	if (elem->content == NULL)
		return ;
	temp = elem;
	printf("%d\n", *(int*)(temp->content));
}

void	ft_printsize_function(t_list *elem)
{
	t_list	*temp;

	if (elem->content == NULL)
		return ;
	temp = elem;
	printf("%ld\n", temp->content_size);
}

t_list		*ft_lstmap_function(t_list *elem)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(*new));
	if (new != NULL)
	{
		if (elem->content != NULL)
		{
			new->content = (void*)malloc(elem->content_size);
			if (new->content != NULL)
			{
				new->content = ft_memcpy(new->content, elem->content, elem->content_size);
				new->content_size = elem->content_size;
			}
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
		return (new);
	}
	free(new);
	new = NULL;
	return (new);
}

/*t_list  *lstmap_test_fn(t_list *list)
{
	t_list  *l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

static void test1()
{
t_list  *list;
t_list  *map;

bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
list->content_size = 21;
list->content = strdup("abc");
list->next->content_size = 100;
list->next->content = strdup("abc");
map = ft_lstmap(list, lstmap_test_fn);
if (!!map && map->content_size == 42)
	printf("OK.\n");
if (!!map && map->next->content_size == 200)
	printf("OK.\n");
}*/

void	ft_iter_test(void)
{
	t_list	*one;
	int		nb1;
	int		nb2;
	int		nb3;

	nb1 = 22;
	nb2 = 33;
	nb3 = 44;
	one = ft_lstnew(&nb1, sizeof(int));
	ft_mainlstadd(&one, ft_lstnew(&nb2, sizeof(int)));
	ft_mainlstadd(&one, ft_lstnew(&nb3, sizeof(int)));
	yellow();
	printf("ft_lstiter: Iterate a function at all items in a list. Result was: \n");
	printf("\033[0m");
	ft_lstiter(one, ft_lstiter_function);
	ft_main_list_clearer(&one);
}

void	ft_map_test(void)
{
	t_list	*one;
	t_list	*two;
	int		nb1;
	int		nb2;
	int		nb3;

	nb1 = 22;
	nb2 = 33;
	nb3 = 44;
	one = ft_lstnew(&nb1, sizeof(int));
	ft_lstadd(&one, ft_lstnew(&nb2, sizeof(int)));
	ft_lstadd(&one, ft_lstnew(&nb3, sizeof(int)));
	yellow();
	printf("ft_lstmap: Create a copy of a list by iterating a function to the all items in a list. Result was: \n");
	printf("\033[0m");
	two = ft_lstmap(one, ft_lstmap_function);
	if (*(int*)(one->content) == *(int*)(two->content))
		printf("Head elem OK.\n");
	else
		printf("Head elem KO.\n");
	if (*(int*)(one->next->content) == *(int*)(two->next->content))
		printf("Next elem OK.\n");
	else
		printf("Next elem KO.\n");
	if (*(int*)(one->next->next->content) == *(int*)(two->next->next->content))
		printf("Last elem OK.\n");
	else
		printf("Last elem KO.\n");
	ft_main_list_clearer(&one);
	ft_main_list_clearer(&two);
}


int		main(int argc, char **argv)
{
	if (argc == 3)
	{

		ft_putcha_test(argv[1], argv[2]);
		ft_strequ_tester();
		ft_strnequ_tester();
		ft_strsub_tester();
		ft_strjoin_tester(argv[1], argv[2]);
		ft_strtrim_tester(argv[1], argv[2]);
		ft_strsplit_tester();
		ft_itoa_tester();
		ft_putcha_test2(argv[1], argv[2]);
		/*ft_putnbr_test();
		ft_putnbr_fd_test();
		ft_memset_test();
		ft_bzero_test();
		ft_memcpy_test();
		ft_memccpy_test();
		ft_memmove_tester();
		ft_memchr_tester();
		ft_memcmp_tester(argv[1], argv[2]);*/
		/*tested*/
		/*ft_strlen_test(argv[1], argv[2]);
		ft_strdup_test(argv[1], argv[2]);
		ft_strcpy_test(argv[1], argv[2]);
		ft_strncpy_test(argv[1], argv[2]);
		ft_strcat_tester(argv[1], argv[2]);
		ft_strncat_tester(argv[1], argv[2]);
		ft_strlcat_tester(argv[1], argv[2]);
		ft_strchr_test(argv[1], argv[2]);
		ft_strrchr_test(argv[1], argv[2]);
		ft_strstr_test(argv[1], argv[2]);
		ft_strnstr_tester(argv[1], argv[2]);
		ft_strcmp_test(argv[1], argv[2]);
		ft_atoi_test(argv[1], argv[2]);
		ft_is_test();
		ft_memalloc_tester(9);
		ft_memdel_tester();
		ft_strnew_tester(9);
		ft_strdel_tester();
		ft_strclr_tester();
		ft_striter_tester(argv[1], argv[2]);
		ft_striteri_tester(argv[1], argv[2]);
		ft_strmap_test();
		ft_strmapi_test();
		ft_lstnew_test();
		ft_lstdelone_test();
		ft_lstdel_test();
		ft_lstadd_test();
		ft_iter_test();
		ft_map_test();*/
		/*tested*/
	}
	return (0);
}
