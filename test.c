/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:23:30 by mclaudel          #+#    #+#             */
/*   Updated: 2020/03/10 12:08:01 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	strcmp_test(char *s1, char *s2)
{
	printf("%-10d vs %10d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	strcy_test(char *src)
{
	char dest1[11];
	char dest2[11];
	char *r1;
	char *r2;

	r1 = strcpy(dest1, src);
	r2 = ft_strcpy(dest2, src);
	printf("src: \"%s\"\n\tdest1:|%s|\tr1=%p vs dst1=%p\n\tdest2:|%s|\tr2=%p vs dst2=%p\n",
											src, dest1, r1, dest1, dest2, r2, dest2);
}

void	write_test(int fd, char *buff, int nb)
{
	int r1;
	int r2;

	printf("-------------------\n");
	r1 = ft_write(fd, buff, nb);
	r2 = write(fd, buff, nb);
	printf("%-7d vs %7d\n", r1, r2);
}

int		main(void)
{
	printf("\e[1;34m======= ft_strlen =======\e[0m\n");
	printf("%-10d vs %10lu\n", ft_strlen(""), strlen(""));
	printf("%-10d vs %10lu\n", ft_strlen("\n"), strlen("\n"));
	printf("%-10d vs %10lu\n", ft_strlen("a"), strlen("a"));
	printf("%-10d vs %10lu\n", ft_strlen("Hello"), strlen("Hello"));
	printf("%-10d vs %10lu\n", ft_strlen("Hel\0lo"), strlen("Hel\0lo"));

	printf("\e[1;34m======= ft_strcpy =======\e[0m\n");
	strcy_test("hello moto");
	strcy_test("");
	strcy_test("aaaa\0aaaa");

	printf("\e[1;34m======= ft_strcmp =======\e[0m\n");
	strcmp_test("", "");
	strcmp_test("a", "a");
	strcmp_test("a", "aa");
	strcmp_test("aaaaa", "");
	strcmp_test("", "aaaa");
	strcmp_test("asdasdas", "qfoprqqq");
	strcmp_test("a", "a\200");

	printf("\e[1;34m======= ft_write =======\e[0m\n");
	write_test(1, "ft_write test plz\n", 18);
	write_test(666, "ft_write test plz\n", 18);
	write_test(1, "", 0);
	write_test(666, "", 0);
	write_test(1, "ft_write test plz\n", -18);
	write_test(666, "ft_write test plz\n", -18);

	printf("\e[1;34m======= ft_read =======\e[0m\n");
	// printf("\n\n\n\n\n");	
	// char buff[100];
	// int fd = open("libasm.h", O_RDONLY);
	// bzero(buff, 100);
	// while ((r = ft_read(fd, buff, 10)) > 0)
	// {
	// 		printf("%d|\t%s\n", r, buff);
	// 		bzero(buff, 100);
	// }
	// printf("END OF TESTS\n");

	printf("\e[1;34m======= ft_strdup =======\e[0m\n");
	char *str;

	str= ft_strdup("Hello moto");
	printf("%p |%s|\n", str, str);
	free(str);
	return (0);
}
