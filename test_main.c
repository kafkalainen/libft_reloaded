/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:42:20 by jnivala           #+#    #+#             */
/*   Updated: 2020/06/18 16:50:05 by jnivala          ###   ########.fr       */
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

void ft_memchr_tester()
{
	char *test;

	test = (char*)malloc(sizeof(*test) * 15);
	strcpy(test, "Hello it's me.");
	printf("ft_memchr: searches mem for char c and returns a pointer to where first instance is found.\n");
	ft_memory_function_tester(ft_memchr(test, 'r', 14), memchr(test, 'r', 14));
	ft_memory_function_tester(ft_memchr(test, '.', 14), memchr(test, '.', 14));
	ft_memory_function_tester(ft_memchr(test, 'o', 20), memchr(test, 'o', 20));
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
	str2 = (char*)malloc(sizeof(*str2) * 9);
	str3 = (char*)malloc(sizeof(*str3) * 20);
	str4 = (char*)malloc(sizeof(*str4) * 9);
	test = (char*)malloc(sizeof(*test) * 15);
	strcpy(str, "Hello I am original");
	strcpy(str2, "Yes I am");
	strcpy(str3, "Hello I am original");
	strcpy(str4, "Yes I am");
	strcpy(test, "No you're not");
	ft_memmove(str, test, 15);
	ft_memmove(str2, str2 + 5, 10);
	memmove(str3, test, 15);
	memmove(str4, str4 + 5, 10);
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
	ft_memory_function_tester(str, NULL);
	ft_memory_function_tester(tab, NULL);
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
	ft_memory_function_tester(str, NULL);
	ft_memory_function_tester(str2, NULL);
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

void	ft_rot_char(unsigned int i, char c)
{
	c = c + i;
	write(1, &c, 1);
}

void	ft_striter_tester(char *s1, char *s2)
{
	yellow();
	printf("Test ft_striter: Testing that str_iter iterates a function.\n");
	printf("\033[0m");
	printf("a\n");
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
	ft_striteri(s1, (void*)ft_rot_char);
	ft_putchar_fd('\n', 1);
	ft_striteri(s2, (void*)ft_rot_char);
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
	ft_strcpy(s1_new, ft_strmapi(s1, (void*)ft_rot_char));
	ft_strcpy(s2_new, ft_strmapi(s2, (void*)ft_rot_char));
	ft_putendl_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	ft_putendl_fd(s1_new, 2);
	ft_putendl_fd(s2_new, 2);
	free(s1_new);
	free(s2_new);
	s1_new = NULL;
	s2_new = NULL;
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
	ft_string_function_tester(ft_strsub("Cut off this part Hello World!", 18, 12), "Hello World!");
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
	ft_memory_function_tester(ft_memset(str1, '$', 5), memset(str2, '$', 5));
	ft_memory_function_tester(ft_memset(str3, '$', 15), memset(str4, '$', 15));
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
	ft_memory_function_tester(str, str2);
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
	ft_memory_function_tester(ft_memcpy(str, "hello", 7), memcpy(str2, "hello", 7));
	free(str);
	free(str2);
}

void	ft_memccpy_test()
{

	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *cpstr = "This is a string: not copied.";

	str = (char*)malloc(sizeof(*str) * 30);
	str2 = (char*)malloc(sizeof(*str2) * 30);
	str3 = (char*)malloc(sizeof(*str3) * 12);
	str4 = (char*)malloc(sizeof(*str4) * 12);
	ft_strcpy(str3, "laaelectric");
	ft_strcpy(str4, "laaelectric");
	yellow();
	printf("ft_memccpy: copies n bytes from src to dest. Returns a pointer to dest + i if c is found.\n");
	printf("\033[0m");
	ft_memccpy(str, cpstr, ':', 30);
	memccpy(str2,  cpstr, ':', 30);
	ft_string_function_tester(str, str2);
	free(str);
	free(str2);
	ft_putendl("If electric is printed, first part of the string was correctly copied.");
	ft_memory_function_tester(ft_memccpy(str3, "eel", 'l', 3), memccpy(str4, "eel", 'l', 3));
	free(str3);
	free(str4);
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

	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	str2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s2) + 1));
	str3 = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	str4 = (char*)malloc(sizeof(*s2) * (ft_strlen(s2) + 1));
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
	yellow();
	printf("ft_strncmp: Compared two params until half of the length of param. Result was: \n");
	printf("\033[0m");
	ft_cmp_function_tester(ft_strncmp(s1, str, ft_strlen(str) / 2), strncmp(s1, str, ft_strlen(str) / 2));
	ft_cmp_function_tester(ft_strncmp(s2, str2, ft_strlen(str2) / 2), strncmp(s2, str2, ft_strlen(str) / 2));
	ft_cmp_function_tester(ft_strncmp("aaaaaa", "aaaaaaaaaa", 5), strncmp("aaaaaa", "aaaaaaaaaa", 5));
	ft_cmp_function_tester(ft_strncmp("aaaaab", "aaaaaaaaaa", 5), strncmp("aaaaab", "aaaaaaaaaa", 5));
	ft_cmp_function_tester(ft_strncmp("baaaab", "aaaaaaaaaa", 5), strncmp("baaaab", "aaaaaaaaaa", 5));
	ft_cmp_function_tester(ft_strncmp("aacaab", "aaaaaaaaaa", 3), strncmp("aacaab", "aaaaaaaaaa", 3));
	ft_cmp_function_tester(ft_strncmp("axcaab", "aaaaaaaaaa", 3), strncmp("axcaab", "aaaaaaaaaa", 3));
}

void	ft_atoi_test(char *s1, char *s2)
{
	printf("ft_atoi: Stripped strings to an integer. Results were: \n");
	ft_int_function_tester(ft_atoi(s1), atoi(s2));
	ft_int_function_tester(ft_atoi(s1), atoi(s2));
	ft_int_function_tester(ft_atoi("38713813138aaaa"), atoi("38713813138aaaa"));
	ft_int_function_tester(ft_atoi("-387138aaaa"), atoi("-387138aaaa"));
	ft_int_function_tester(ft_atoi("- 42"), atoi("- 42"));
}

void	ft_is_test()
{
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
		ft_int_function_tester(ft_isprint((unsigned char)(20)), isprint((unsigned char)(20)));
		ft_int_function_tester(ft_isprint((unsigned char)('a')), isprint((unsigned char)('a')));
		ft_int_function_tester(ft_isprint((unsigned char)('n')), isprint((unsigned char)('n')));
		ft_int_function_tester(ft_isprint((unsigned char)(127)), isprint((unsigned char)(127)));
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
		ft_strsplit_tester(argv[1], argv[2]);
		ft_itoa_tester();
		ft_putcha_test2(argv[1], argv[2]);
		ft_putnbr_test();
		ft_putnbr_fd_test();
		ft_memset_test();
		ft_bzero_test();
		ft_memcpy_test();
		ft_memccpy_test();
		ft_memmove_tester();
		ft_memchr_tester();
		ft_memcmp_tester(argv[1], argv[2]);
		ft_strlen_test(argv[1], argv[2]);
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
		ft_strmap_test(argv[1], argv[2]);
		ft_strmapi_test(argv[1], argv[2]);
	}
	return (0);
}
