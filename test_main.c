/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:42:20 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/15 18:23:22 by jnivala          ###   ########.fr       */
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

void ft_memory_function_tester(void *own, void *system)
{
	char *o;
	char *s;

	o = own;
	s = system;
	if (own == NULL && system == NULL)
	{
		printf("\033[1;32m");
		printf("both NULL: OK\n");
		printf("\033[0m");
	}
	else
	{
		if (strcmp(o, s) == 0)
		{
			printf("\033[1;32m");
			printf("strcmp after char* cast: OK\n");
			printf("own: %s\nsystem: %s\n", o, s);
			printf("\033[0m");
		}
		else
		{
			printf("\033[1;31m");
			printf("strcmp after char* cast: KO\nown: %s\nsystem: %s\n", o, s);
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
			printf("strcmp: OK\nown: %s\nsystem: %s\n", own, system);
			printf("\033[0m");
		}
		else
		{
			printf("\033[1;31m");
			printf("strcmp: KO\nown: %s\nsystem: %s\n", own, system);
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
		printf("diff: OK\nown: %d\nsystem: %d\n", own, system);
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("diff: KO\nown: %d\nsystem: %d\n", own, system);
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

void ft_memchr_tester(void *s, int c, size_t n)
{
	printf("ft_memchr: searches mem for char c and returns a pointer to where first instance is found.\n");
	//ft_memory_function_tester(ft_memchr(s, c, n), memchr(s, n, n));
	ft_string_function_tester((char*)ft_memchr(s, c, n), (char*)memchr(s, c, n));
}

void ft_memmove_tester(void* dest, const void* src, size_t n)
{
	char *str;
	char *str2;

	str = (char*)malloc(sizeof(*str) * n);
	str2 = (char*)malloc(sizeof(*str) * n);
	strcpy(str, dest);
	strcpy(str2, dest);
	//printf("%s\n", str);
	//printf("%p\n", str);
	//printf("%s\n", str2);
	//printf("%p\n", str2);
	memmove(str, src, n);
	ft_memmove(str2, src, n);
	ft_string_function_tester(str, str2);
	//printf("%s\n", str);
	//printf("%p\n", str);
	//printf("%s\n", str2);
	//printf("%p\n", str2);
	free(str);
	free(str2);
}

void	ft_memcmp_tester(char *s2, char *s1, size_t size)
{
	char str1[15];
	char str2[15];
	char *str3;
	char *str4;
	char *str5;
	char *str6;
	char str7[15];
	char str8[15];
	int tab1[100];
	int tab2[100];
	int ret1;
	int ret2;
	int i;

	i = 0;
	while (i < 100)
	{
		tab1[i] = i;
		tab2[i] = i;
		i++;
	}
	tab2[41] = 42;
	str3 = (char*)malloc(sizeof(*str3) * 100 + 1);
	str4 = (char*)malloc(sizeof(*str4) * 100 + 1);
	str5 = (char*)malloc(sizeof(*str5) * 100 + 1);
	str6 = (char*)malloc(sizeof(*str6) * 100 + 1);
	memcpy(str2, "abcdef", 6);
	memcpy(str1, "ABCDEF", 6);
	memcpy(str3, s1, size);
	memcpy(str4, s2, size);
	memcpy(str5, s1, size);
	memcpy(str6, s2, size);
	memcpy(str7, "abcdef", 6);
	memcpy(str8, "ABC", 3);
	printf("Comparison of tab1 and tab2 with size 100:\n");
	ret1 = ft_memcmp(tab2, tab1, sizeof(tab1));
	ret2 = memcmp(tab2, tab1, sizeof(tab1));
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABCDEF with size 5:\n");
	ret1 = ft_memcmp(str1, str2, 5);
	ret2 = memcmp(str1, str2, 5);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABCDEF with size 3:\n");
	ret1 = ft_memcmp(str1, str2, 3);
	ret2 = memcmp(str1, str2, 3);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABCDEF with size 2:\n");
	ret1 = ft_memcmp(str1, str2, 2);
	ret2 = memcmp(str1, str2, 2);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABCDEF with size 6:\n");
	ret1 = ft_memcmp(str1, str2, 6);
	ret2 = memcmp(str1, str2, 6);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABCDEF with size 4:\n");
	ret1 = ft_memcmp(str1, str2, 6);
	ret2 = memcmp(str1, str2, 6);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of abcdef and ABC with size 4:\n");
	ret1 = ft_memcmp(str1, str2, 4);
	ret2 = memcmp(str1, str2, 4);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison of full length:\n");
	ret1 = ft_memcmp(str3, str4, size);
	ret2 = memcmp(str3, str4, size);
	ft_cmp_function_tester(ret1, ret2);
	printf("Comparison, where size is way over what it should:\n");
	ret1 = ft_memcmp(str5, str6, 1000);
	ret2 = memcmp(str5, str6, 1000);
	ft_int_function_tester(ret1, ret2);
}

void	ft_strcat_tester(char *s1, char *s2)
{
	char *str1;
	char *str2;
	char str3[50];
	char str4[50];
	char *str5;
	char *str6;
	char str7[10];
	char str8[10];
	//char str9[10];
	//char str10[10];

	str1 = (char*)malloc(sizeof(*str1) * (strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (strlen(s2) + 1));
	str5 = (char*)malloc(sizeof(*str5) * (strlen(s1) + 1));
	str6 = (char*)malloc(sizeof(*str6) * (strlen(s2) + 1));
	printf("ft_strcat: Copied first string to end of an another string. Results were: \n");
	printf("Testing catenation with parameters:\n");
	strcpy(str1, s1);
	strcpy(str2, s2);
	strcpy(str3, s1);
	strcpy(str4, s2);
	strcpy(str5, s1);
	strcpy(str6, s2);
	ft_string_function_tester(ft_strcat(str1, str2), strcat(str1, str2));
	ft_string_function_tester(ft_strcat(str3, str4), strcat(str3, str4));
	ft_string_function_tester(ft_strcat(str5, str6), strcat(str5, str6));
	printf("Testing catenation with fixed length parameters with enough space:\n");
	strcpy(str7, "Hello");
	strcpy(str8, "Hullo");
	ft_string_function_tester(ft_strcat(str7, str8), strcat(str7, str8));
	//printf("Testing catenation with no space in the end:\n");
	//strcpy(str9, "Thisistoo");
	//strcpy(str10, "longforyu");
	//ft_string_function_tester(ft_strcat(str9, str10), strcat(str9, str10));
	free(str1);
	free(str2);
	free(str5);
	free(str6);
}

void	ft_strncat_tester(char *s1, char *s2, size_t n)
{
	char *str1;
	char *str2;
	char *str11;
	char *str12;
	char str3[50];
	char str4[50];
	char str13[50];
	char str14[50];
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


	str1 = (char*)malloc(sizeof(*str1) * (strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (strlen(s2) + 1));
	str5 = (char*)malloc(sizeof(*str5) * (strlen(s1) + 1));
	str6 = (char*)malloc(sizeof(*str6) * (strlen(s2) + 1));
	str11 = (char*)malloc(sizeof(*str11) * (strlen(s1) + 1));
	str12 = (char*)malloc(sizeof(*str12) * (strlen(s2) + 1));
	str15 = (char*)malloc(sizeof(*str15) * (strlen(s1) + 1));
	str16 = (char*)malloc(sizeof(*str16) * (strlen(s2) + 1));
	printf("ft_strncat: Copied first three characters to end of an another string. Results were: \n");
	printf("Testing catenation with parameters:\n");
	strcpy(str1, s1);
	strcpy(str2, s2);
	strcpy(str3, s1);
	strcpy(str4, s2);
	strcpy(str5, s1);
	strcpy(str6, s2);
	strcpy(str11, s1);
	strcpy(str12, s2);
	strcpy(str13, s1);
	strcpy(str14, s2);
	strcpy(str15, s1);
	strcpy(str16, s2);
	ft_string_function_tester(ft_strncat(str1, str2, n), strncat(str11, str12, n));
	ft_string_function_tester(ft_strncat(str3, str4, n), strncat(str13, str14, n));
	ft_string_function_tester(ft_strncat(str5, str6, n), strncat(str15, str16, n));
	printf("Testing catenation with fixed length parameters with enough space:\n");
	strcpy(str7, "Hello");
	strcpy(str8, "Hullo");
	strcpy(str17, "Hello");
	strcpy(str18, "Hullo");
	ft_string_function_tester(ft_strncat(str7, str8, 2), strncat(str17, str18, 2));
	printf("Testing catenation with no space in the end:\n");
	strcpy(str9, "Thisistoo");
	strcpy(str10, "longforyu");
	strcpy(str19, "Thisistoo");
	strcpy(str20, "longforyu");
	ft_string_function_tester(ft_strncat(str9, str10, 6), strncat(str19, str20, 6));
	free(str1);
	free(str2);
	free(str5);
	free(str6);
	free(str11);
	free(str12);
	free(str15);
	free(str16);
}

void	ft_strlcat_tester(char *s1, char *s2, size_t n)
{
	char *str1;
	char *str2;
	char *str11;
	char *str12;
	char str3[50];
	char str4[50];
	char str13[50];
	char str14[50];
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

	printf("%ld\n", n);
	str1 = (char*)malloc(sizeof(*str1) * (strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*str2) * (strlen(s2) + 1));
	str5 = (char*)malloc(sizeof(*str5) * (strlen(s1) + 1));
	str6 = (char*)malloc(sizeof(*str6) * (strlen(s2) + 1));
	str11 = (char*)malloc(sizeof(*str11) * (strlen(s1) + 1));
	str12 = (char*)malloc(sizeof(*str12) * (strlen(s2) + 1));
	str15 = (char*)malloc(sizeof(*str15) * (strlen(s1) + 1));
	str16 = (char*)malloc(sizeof(*str16) * (strlen(s2) + 1));

	yellow();
	printf("Test ft_strlcat: Copied first string to end of an another string. Results were: \n");
	ft_default();
	printf("Testing catenation with parameters:\n");
	strcpy(str1, s1);
	strcpy(str2, s2);
	strcpy(str3, s1);
	strcpy(str4, s2);
	strcpy(str5, s1);
	strcpy(str6, s2);
	strcpy(str11, s1);
	strcpy(str12, s2);
	strcpy(str13, s1);
	strcpy(str14, s2);
	strcpy(str15, s1);
	strcpy(str16, s2);
	printf("Testing return values:\n");
	ft_long_int_function_tester(ft_strlcat(str1, str2, sizeof(str1)), strlcat(str11, str12, sizeof(str11)));
	ft_long_int_function_tester(ft_strlcat(str3, str4, sizeof(str3)), strlcat(str13, str14, sizeof(str13)));
	ft_long_int_function_tester(ft_strlcat(str5, str6, sizeof(str5)), strlcat(str15, str16, sizeof(str15)));
	printf("Testing catenated strings:\n");
	ft_string_function_tester(str1, str11);
	ft_string_function_tester(str3, str13);
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

void	ft_strnstr_tester(char *big, char *little, size_t n)
{
	yellow();
	printf("Test ft_strnstr: Testing that substring can be found.\n");
	ft_default();
	printf("Testing with a string with limited length, answer is behind\n");
	ft_string_function_tester(ft_strnstr("Can't find me", "me", 11), strnstr("Can't find me", "me", 11));
	printf("search using a first string of par with limited length of 5\n");
	printf("both functions make a segfault if parameter is too short: aaanaa naa\n");
	ft_string_function_tester(ft_strnstr(big, little, n), strnstr(big, little, n));
	printf("search using a first string of par with empty string of limited length of 5\n");
	ft_string_function_tester(ft_strnstr(big, "", n), strnstr(big, "", n));
	printf("search using a first string of par with null string of limited length of 5\n");
	printf("segfault tester: uncomment to test\n");
	//ft_string_function_tester(ft_strnstr(big, NULL, n), strnstr(big, NULL, n));
	printf("Testing with a string with limited length, answer is behind null terminator\n");
	ft_string_function_tester(ft_strnstr("Can't\0me find", "me", 11), strnstr("Can't\0me find", "me", 11));
	printf("Testing with a string with limited length, answer is found\n");
	ft_string_function_tester(ft_strnstr("Can't me find", "me", 11), strnstr("Can't me find", "me", 11));
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
}
void	ft_memdel_tester()
{
	char	**str;
	int		i;

	i = 0;
	str = (char**)malloc(sizeof(**str) * 10);
	while (i < 10)
	{
		str[i] = (char*)malloc(sizeof(*str) * (21));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		strcpy(str[i], "I'm mister Meeseks.");
		i++;
	}
	yellow();
	printf("Test ft_memdel: Testing that strdel removes data from allocated memory.\n");
	ft_default();
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	printf("%s\n", str[5]);
	printf("%s\n", str[6]);
	printf("%s\n", str[7]);
	printf("%s\n", str[8]);
	printf("%s\n", str[9]);
	ft_memdel((void**)str);
	/*printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	printf("%s\n", str[5]);
	printf("%s\n", str[6]);
	printf("%s\n", str[7]);
	printf("%s\n", str[8]);
	printf("%s\n", str[9]);*/
}

void	ft_strdel_tester()
{
	/*char	**str;
	int		i;

	i = 0;
	str = (char**)malloc(sizeof(**str) * 10);
	while (i < 10)
	{
		str[i] = (char*)malloc(sizeof(*str) * (21));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		strcpy(str[i], "I'm mister Meeseks.");
		i++;
	}
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	printf("%s\n", str[4]);
	printf("%s\n", str[5]);
	printf("%s\n", str[6]);
	printf("%s\n", str[7]);
	printf("%s\n", str[8]);
	printf("%s\n", str[9]);*/
	yellow();
	printf("Test ft_strdel: NOT WORKING Testing that strdel removes data from allocated memory.\n");
	ft_default();
	/*ft_strdel(str);
	printf("test %s\n", str[0]);
	printf("test %s\n", str[1]);
	printf("test %s\n", str[2]);
	printf("test %s\n", str[3]);
	printf("test %s\n", str[4]);
	printf("%s\n", str[5]);
	printf("%s\n", str[6]);
	printf("%s\n", str[7]);
	printf("%s\n", str[8]);
	printf("%s\n", str[9]);*/
}


void	ft_strclr_tester(void)
{
	char	**str;
	int		i;

	i = 0;
	str = (char**)malloc(sizeof(**str) * 3);
	while (i < 3)
	{
		str[i] = (char*)malloc(sizeof(*str) * (21));
		i++;
	}
	i = 0;
	while (i < 3)
	{
		ft_strcpy(str[i], "I'm mister Meeseks.");
		i++;
	}
	yellow();
	printf("Test ft_strclr: Tests with three strings that are null terminated that nothing is printed out.\n");
	ft_default();
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	ft_strclr(str[0]);
	ft_strclr(str[1]);
	ft_strclr(str[2]);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
}

void	ft_strnew_tester(size_t n)
{
	void *str;
	void *str2;

	str = ft_memalloc(n);
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
}

void	ft_putstr(char *s)
{
	write(1, s, strlen(s));
}

void	ft_striter_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_striter: Testing that str_iter iterates a function.\n");
	printf("\033[0m");
	printf("a\n");
	ft_striter(s1, ft_putstr);
	ft_putchar_fd('\n', 1);
	ft_striter(s2, ft_putstr);
	ft_putchar_fd('\n', 1);
	ft_striter("Hello", ft_putstr);
	ft_putchar_fd('\n', 1);
}

void	ft_putcha_test(char *s1, char *s2)
{
	yellow();
	printf("Test ft_putchar_fd: Testing that ft_putchar puts out a character.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putchar_fd(s1[0], 1);
	ft_putchar_fd(s2[0], 1);
	yellow();
	printf("Test ft_putstr_fd: Testing that ft_putstr puts out a string.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putstr_fd(s1, 1);
	ft_putstr_fd(s2, 1);
	ft_putchar_fd('\n', 1);
	yellow();
	printf("Test ft_putendl_fd: Testing that ft_puendl puts out a string with nl to 2 fd.\n");
	printf("\033[0m");
	printf("a\n");
	ft_putendl_fd(s1, 2);
	ft_putendl_fd(s2, 2);
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
	return (c + i);
}

void	ft_strmap_test(char *s1, char *s2)
{
	char *s1_new;
	char *s2_new;

	s1_new = (char*)malloc(sizeof(*s1_new) * (ft_strlen(s1) + 1));
	s2_new = (char*)malloc(sizeof(*s2_new) * (ft_strlen(s2) + 1));
	yellow();
	printf("Test ft_strmap: Testing strmap by using ft_upper char version, and printing resulting string.\n");
	printf("\033[0m");
	printf("a\n");
	ft_strcpy(s1_new, ft_strmap(s1, ft_toupper_char));
	ft_strcpy(s2_new, ft_strmap(s2, ft_toupper_char));
	ft_putendl_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	ft_putendl_fd(s1_new, 2);
	ft_putendl_fd(s2_new, 2);
	free(s1_new);
	free(s2_new);
}

void	ft_strmapi_test(char *s1, char *s2)
{
	char *s1_new;
	char *s2_new;

	s1_new = (char*)malloc(sizeof(*s1_new) * (ft_strlen(s1) + 1));
	s2_new = (char*)malloc(sizeof(*s2_new) * (ft_strlen(s2) + 1));
	yellow();
	printf("Test ft_strmapi: Testing strmap by using ft_upper char version, and printing resulting string.\n");
	printf("\033[0m");
	printf("a\n");
	ft_strcpy(s1_new, ft_strmapi(s1, ft_rot_char));
	ft_strcpy(s2_new, ft_strmapi(s2, ft_rot_char));
	ft_putendl_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	ft_putendl_fd(s1_new, 2);
	ft_putendl_fd(s2_new, 2);
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
	yellow();
	printf("Test ft_strsub: Testing by giving it string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with 'Cut off this part Hello World!'.", 1);
	ft_string_function_tester(ft_strsub("Cut off this part Hello World!", 18, 13), "Hello World!");
	printf("<\n");
	//ft_putendl_fd("test with 'Cut off this part Hello World!' with illegal values 150 and 100.", 1);
	//ft_putendl_fd(ft_strsub("Cut off this part Hello World!", 150, 100), 1);
	//printf("<\n");
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

void	ft_strsplit_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_strsplit: Testing it by giving it few string literals and comparing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with '    Hello     ' and '     Hel    lo     '.", 1);
	ft_string_function_tester(ft_strsplit("    Hello     ", ' ')[0], "Hello");
	ft_string_function_tester(ft_strsplit("     Hel    lo     ", ' ')[1], "lo");
	ft_string_function_tester(ft_strsplit("     Marvin    rules     ", ' ')[1], "rules");
	ft_string_function_tester(ft_strsplit("     Coffee  breaks are for weak.", ' ')[1], "breaks");
	ft_string_function_tester(ft_strsplit("%%%%%%Galaxy is%%%%for%%%%all.", '%')[0], "Galaxy is");
	printf("<\n");
	ft_putendl_fd("test with parameters.", 1);
	ft_putendl_fd(ft_strjoin(s1, s2), 1);
}

void	ft_itoa_tester()
{
	yellow();
	printf("Test ft_itoa: Testing it by giving it few integrals and printf:ing those.\n");
	printf("\033[0m");
	printf(":\n");
	ft_putendl_fd("test with '12345' and '-12345'.", 1);
	ft_string_function_tester(ft_itoa(12345), "12345");
	ft_string_function_tester(ft_itoa(-12345), "-12345");
	printf("<\n");
}

int		main(int argc, char **argv)
{
	size_t	str_len;
	size_t	str_len1;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char 	*str9;
	char 	*str10;
	void	*str11;
	void	*str12;
	void	*str13;
	void	*str14;
	void	*str15;
	void	*str16;
	void	*str17;
	void	*str18;
	void	*str19;
	void	*str20;
	void	*str21;
	void	*str22;
	void	*str23;
	void	*str24;
	char	*str25;
	char	*str26;
	char	*str27;
	char	*str28;
	char	*str29;
	char	*str30;
	char	*str31;
	char	*str32;

	if (argc == 1)
	{
		printf("%ld\n", ft_strlen("Lazy fox is a lazy"));
		printf("%ld\n", strlen("Lazy fox is a lazy"));
		write(1, "strlen: Test 'Lazy fox is a lazy' and it was 18 char long.\n", 59);
		write(1, ft_strdup("Lazy fox is a lazy\n"), 19);
		write(1, "strdup: Test lazy fox is a lazy, use source to duplicate.\n", 58);
		printf("%d\n", ft_strcmp("lazy", "hazy"));
	}
	if (argc == 3)
	{
		str_len = ft_strlen(argv[2]);
		str_len1 = ft_strlen(argv[1]);
		str1 = (char*)malloc(sizeof(*str1) * (str_len + 1));
		str2 = (char*)malloc(sizeof(*str2) * (str_len + 1));
		str3 = (char*)malloc(sizeof(*str3) * (str_len + 1));
		str4 = (char*)malloc(sizeof(*str4) * (str_len + 1));
		str5 = (char*)malloc(sizeof(*str5) * (str_len + str_len1 + 1));
		str6 = (char*)malloc(sizeof(*str6) * (str_len + str_len1 + 1));
		str9 = (char*)malloc(sizeof(*str9) * (str_len + str_len1 + 1));
		str10 = (char*)malloc(sizeof(*str10) * (str_len + str_len1 + 1));
		str11 = (void*)malloc(sizeof(*str11) * 10);
		str12 = (void*)malloc(sizeof(*str12) * 10);
		str13 = (void*)malloc(sizeof(*str13) * 500);
		str14 = (void*)malloc(sizeof(*str14) * 500);
		str15 = (void*)malloc(sizeof(*str15) * 1000);
		str16 = (void*)malloc(sizeof(*str16) * 1000);
		str17 = (void*)malloc(sizeof(*str17) * 1000);
		str18 = (void*)malloc(sizeof(*str18) * 1000);
		str19 = (void*)malloc(sizeof(*str19) * 1000);
		str20 = (void*)malloc(sizeof(*str20) * 1000);
		str21 = (void*)malloc(sizeof(*str21) * 1000);
		str22 = (void*)malloc(sizeof(*str22) * 1000);
		str23 = (void*)malloc(sizeof(*str23) * 1000);
		str24 = (void*)malloc(sizeof(*str24) * 1000);
		str25 = (char*)malloc(sizeof(*str25) * 1000);
		str26 = (char*)malloc(sizeof(*str26) * 1000);
		str27 = (char*)malloc(sizeof(*str27) * 1000);
		str28 = (char*)malloc(sizeof(*str28) * 1000);
		str29 = (char*)malloc(sizeof(*str29) * 1000);
		str30 = (char*)malloc(sizeof(*str30) * 1000);
		str31 = (char*)malloc(sizeof(*str31) * 1000);
		str32 = (char*)malloc(sizeof(*str32) * 1000);
		printf("strcmp: Compared two strings. Result was: \n");
		ft_long_int_function_tester(ft_strcmp(argv[1], argv[2]), strcmp(argv[1], argv[2]));
		printf("ft_strncmp: Compared two strings until fifth byte. Result was: \n");
		ft_long_int_function_tester(ft_strncmp(argv[1], argv[2], 5), strncmp(argv[1], argv[2], 5));
		ft_long_int_function_tester(ft_strncmp("aaaaaa", "aaaaaaaaaa", 5), strncmp("aaaaaa", "aaaaaaaaaa", 5));
		ft_long_int_function_tester(ft_strncmp("aaaaab", "aaaaaaaaaa", 5), strncmp("aaaaab", "aaaaaaaaaa", 5));
		ft_long_int_function_tester(ft_strncmp("baaaab", "aaaaaaaaaa", 5), strncmp("baaaab", "aaaaaaaaaa", 5));
		ft_long_int_function_tester(ft_strncmp("aacaab", "aaaaaaaaaa", 3), strncmp("aacaab", "aaaaaaaaaa", 3));
		ft_long_int_function_tester(ft_strncmp("axcaab", "aaaaaaaaaa", 3), strncmp("axcaab", "aaaaaaaaaa", 3));
		printf("ft_atoi: Stripped strings to an integer. Results were: \n");
		ft_int_function_tester(ft_atoi(argv[1]), atoi(argv[1]));
		ft_int_function_tester(ft_atoi(argv[2]), atoi(argv[2]));
		printf("ft_strcpy: Copied first strings to an another string. Results were: \n");
		strcpy(str1, argv[2]);
		strcpy(str2, argv[2]);
		ft_string_function_tester(ft_strcpy(str1, argv[1]), strcpy(str2, argv[1]));
		free(str1);
		printf("ft_strncpy: Copied first strings to an another string for 5 bytes. Results were: \n");
		strcpy(str3, argv[2]);
		strcpy(str4, argv[2]);
		ft_string_function_tester(ft_strncpy(str3, argv[1], 5), strncpy(str4, argv[1], 5));
		free(str3);
		printf("ft_strchr: Returns pointer to first occurance in a string and using first letter. Results were: \n");
		ft_string_function_tester(ft_strchr(argv[1], argv[2][0]), strchr(argv[1], argv[2][0]));
		printf("Original string was: %s\n", argv[1]);
		printf("ft_strrchr: Returns pointer to the last occurance in a string and using first letter. Results were: \n");
		ft_string_function_tester(ft_strrchr(argv[1], argv[2][0]), strrchr(argv[1], argv[2][0]));
		printf("Original string was: %s\n", argv[1]);
		printf("ft_strstr: Returns pointer to the first occurance of a substring and using substring. Results were: \n");
		ft_string_function_tester(ft_strstr(argv[1], argv[2]), strstr(argv[1], argv[2]));
		printf("Original string was: %s\n", argv[1]);
		ft_string_function_tester(ft_strstr("NOt gonne find me", "Hello"), strstr("NOt gonne find me", "Hello"));
		printf("Original strings were: NOt gonne find me and Hello\n");
		printf("ft_isalpha: Validates that unsigned char is part of alphabet. Results were: \n");
		ft_int_function_tester(ft_isalpha('a'), isalpha('a'));
		ft_int_function_tester(ft_isalpha('H'), isalpha('H'));
		ft_int_function_tester(ft_isalpha('!'), isalpha('!'));
		printf("ft_isdigit: Validates that integer is part of digits. Results were: \n");
		ft_int_function_tester(ft_isdigit('0'), isdigit('0'));
		ft_int_function_tester(ft_isdigit('1'), isdigit('1'));
		ft_int_function_tester(ft_isdigit('2'), isdigit('2'));
		ft_int_function_tester(ft_isdigit('3'), isdigit('3'));
		ft_int_function_tester(ft_isdigit('!'), isdigit('!'));
		printf("ft_isalnum: Validates that tested value is part of alphabet or digits. Results were: \n");
		ft_int_function_tester(ft_isalnum((unsigned char)('0')), isalnum((unsigned char)('0')));
		ft_int_function_tester(ft_isalnum((unsigned char)('a')), isalnum((unsigned char)('a')));
		ft_int_function_tester(ft_isalnum((unsigned char)('n')), isalnum((unsigned char)('n')));
		ft_int_function_tester(ft_isalnum((unsigned char)('u')), isalnum((unsigned char)('u')));
		ft_int_function_tester(ft_isalnum((unsigned char)('!')), isalnum((unsigned char)('!')));
		printf("ft_isascii: Validates that tested value is an ascii character. Results were: \n");
		ft_int_function_tester(ft_isascii((unsigned char)('0')), isascii((unsigned char)('0')));
		ft_int_function_tester(ft_isascii((unsigned char)('a')), isascii((unsigned char)('a')));
		ft_int_function_tester(ft_isascii((unsigned char)('n')), isascii((unsigned char)('n')));
		ft_int_function_tester(ft_isascii((unsigned char)(126)), isascii((unsigned char)(126)));
		ft_int_function_tester(ft_isascii((unsigned char)(184)), isascii((unsigned char)(184)));
		ft_int_function_tester(ft_isascii((unsigned char)(255)), isascii((unsigned char)(255)));
		ft_int_function_tester(ft_isascii((unsigned char)(127)), isascii((unsigned char)(127)));
		printf("ft_isprint: Validates that tested value is a printable character. Results were: \n");
		ft_int_function_tester(ft_isprint((unsigned char)(1)), isprint((unsigned char)(1)));
		ft_int_function_tester(ft_isprint((unsigned char)('a')), isprint((unsigned char)('a')));
		ft_int_function_tester(ft_isprint((unsigned char)('n')), isprint((unsigned char)('n')));
		ft_int_function_tester(ft_isprint((unsigned char)(126)), isprint((unsigned char)(126)));
		ft_int_function_tester(ft_isprint((unsigned char)(184)), isprint((unsigned char)(184)));
		ft_int_function_tester(ft_isprint((unsigned char)(255)), isprint((unsigned char)(255)));
		ft_int_function_tester(ft_isprint((unsigned char)(127)), isprint((unsigned char)(127)));
		printf("ft_toupper: Changes char to uppercase: \n");
		ft_int_function_tester(ft_toupper((unsigned char)(1)), tolower((unsigned char)(1)));
		ft_int_function_tester(ft_toupper((unsigned char)('a')), toupper((unsigned char)('a')));
		ft_int_function_tester(ft_toupper((unsigned char)('z')), toupper((unsigned char)('z')));
		ft_int_function_tester(ft_toupper((unsigned char)('h')), toupper((unsigned char)('h')));
		ft_int_function_tester(ft_toupper((unsigned char)('A')), toupper((unsigned char)('A')));
		ft_int_function_tester(ft_toupper((unsigned char)('B')), toupper((unsigned char)('B')));
		ft_int_function_tester(ft_toupper((unsigned char)(127)), toupper((unsigned char)(127)));
		printf("ft_tolower: Changes char to lowercase: \n");
		ft_int_function_tester(ft_tolower((unsigned char)(1)), tolower((unsigned char)(1)));
		ft_int_function_tester(ft_tolower((unsigned char)('a')), tolower((unsigned char)('a')));
		ft_int_function_tester(ft_tolower((unsigned char)('n')), tolower((unsigned char)('n')));
		ft_int_function_tester(ft_tolower((unsigned char)('H')), tolower((unsigned char)('H')));
		ft_int_function_tester(ft_tolower((unsigned char)('C')), tolower((unsigned char)('C')));
		ft_int_function_tester(ft_tolower((unsigned char)('Z')), tolower((unsigned char)('Z')));
		ft_int_function_tester(ft_tolower((unsigned char)(127)), tolower((unsigned char)(127)));
		printf("ft_memset: fills the first n bytes with constant byte c. Returns pointer.\n");
		ft_memory_function_tester(ft_memset(str11, 1, 10), memset(str12, 1, 10));
		free(str11);
		ft_memory_function_tester(ft_memset(str13, '!', 499), memset(str14, '!', 499));
		free(str13);
		ft_memory_function_tester(ft_memset(str15, 'a', 1000), memset(str16, 'a', 1000));
		free(str15);
		printf("ft_memcpy: copies n bytes from src to dest. Returns a pointer to dest.\n");
		ft_memory_function_tester(ft_memcpy(str17, "hello", 10), memcpy(str18, "hello", 10));
		ft_memory_function_tester(ft_memcpy(str19, "nieria", 499), memcpy(str20, "nieria", 499));
		ft_memory_function_tester(ft_memcpy(str21, "hallo", 1000), memcpy(str22, "hallo", 1000));
		ft_memory_function_tester(ft_memcpy(str23, "hallo", 1000), memcpy(str24, "hallo", 1000));
		printf("ft_bzero: fills void with null characters to n. Returns a pointer to dest.\n");
		ft_bzero(str17, 10);
		bzero(str18, 10);
		ft_memory_function_tester(str17, str18);
		free(str17);
		free(str18);
		ft_bzero(str19, 499);
		bzero(str20, 499);
		ft_memory_function_tester(str19, str20);
		free(str19);
		free(str20);
		ft_bzero(str21, 1000);
		bzero(str22, 1000);
		ft_memory_function_tester(str21, str22);
		free(str21);
		free(str22);
		ft_bzero(str23, 1000);
		bzero(str24, 1000);
		ft_memory_function_tester(str23, str24);
		free(str23);
		free(str24);
		printf("ft_memccpy: copies n bytes from src to dest. Returns a pointer to dest + i if c is found.\n");
		ft_memccpy(str25, "This is a string: not copied", ':', 30);
		memccpy(str26,  "This is a string: not copied", ':', 30);
		ft_string_function_tester(str25, str26);
		ft_string_function_tester(ft_memccpy(str27, "nieria", 'i', 499), memccpy(str28, "nieria", 'i', 499));
		ft_string_function_tester(ft_memccpy(str29, "hallo", 'e', 1000), memccpy(str30, "hallo", 'e', 1000));
		ft_string_function_tester(ft_memccpy(str31, "hallo", 'e', 1000), memccpy(str32, "hallo", 'e', 1000));
		ft_memchr_tester("Hello it's me.", '.', 50);
		ft_memchr_tester("Hello it's me.", ',', 50);
		ft_memchr_tester("Hello it's me.", 'm', 50);
		ft_memchr_tester("Hello it's me.", 'i', 50);
		ft_memchr_tester("Hello it's me.", 'H', 50);
		printf("ft_memmove: moves a src to a temp and copies temp to dest and returns a pointer to dest.\n");
		ft_memmove_tester("Hello I am original", "No you're not", 20);
		ft_memmove_tester("Yes I am", "No you're not", 4);
		ft_memmove_tester("Will you take me as a fraud?", "No you're not", 300);
		ft_memcmp_tester(argv[1], argv[2], sizeof(argv[1]));
		ft_strcat_tester(argv[1], argv[2]);
		ft_strncat_tester(argv[1], argv[2], sizeof(argv[2]));
		ft_strlcat_tester(argv[1], argv[2], ft_strlen(argv[1]));
		ft_strnstr_tester(argv[1], argv[2], 5);
		ft_memalloc_tester(9);
		ft_memdel_tester();
		ft_strnew_tester(9);
		ft_strdel_tester();
		ft_strclr_tester();
		ft_striter_tester(argv[1], argv[2]);
		ft_putcha_test(argv[1], argv[2]);
		ft_strmap_test(argv[1], argv[2]);
		ft_strmapi_test(argv[1], argv[2]);
		ft_strequ_tester();
		ft_strnequ_tester();
		ft_strsub_tester();
		ft_strjoin_tester(argv[1], argv[2]);
		ft_strtrim_tester(argv[1], argv[2]);
		ft_strsplit_tester(argv[1], argv[2]);
		ft_itoa_tester();
	}
	return (0);
}
