/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:23:30 by mclaudel          #+#    #+#             */
/*   Updated: 2020/07/13 12:17:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>

void	strcmp_test(char *s1, char *s2)
{
	int r1;
	int r2;

	r1 = ft_strcmp(s1, s2);
	r2 = strcmp(s1, s2);
	if (r1 == r2)
		printf("OK\n");
	else
		printf("%-10d vs %10d\n", r1, r2);
}

void	strcy_test(char *src)
{
	char dest1[100];
	char dest2[100];
	char *r1;
	char *r2;

	memset(dest1, 42, 100);
	memset(dest2, 42, 100);
	r1 = strcpy(dest1, src);
	r2 = ft_strcpy(dest2, src);
	if (strcmp(dest1, dest2) == 0)
		printf("OK\n");
	else
		printf("src: \"%s\"\n\tdest1:|%s|\tr1=%p vs dst1=%p\n\tdest2:|%s|\tr2=%p vs dst2=%p\n",
											src, dest1, r1, dest1, dest2, r2, dest2);
}

void	write_test(int fd, char *buff, int nb)
{
	int r1;
	int r2;
	int err1;
	int err2;

	printf("-------------------\n");
	r1 = ft_write(fd, buff, nb);
	err1 = errno;
	r2 = write(fd, buff, nb);
	err2 = errno;
	if (r1 == r2 && err1 == err2)
		printf("OK\n");
	else
		printf("%-7d vs %7d  err %d %d\n", r1, r2, err1, err2);
}

void	read_test(int fd1, int fd2, int nb, int isnull)
{
	int r1;
	int r2;
	int	err1;
	int	err2;

	char buff1[100];
	char buff2[100];

	bzero(buff1, 100);
	bzero(buff2, 100);
	printf("-------------------\n");
	r1 = ft_read(fd1, !isnull ? buff1 : 0, nb);
	err1 = errno;
	r2 = read(fd2, !isnull ? buff2 : 0, nb);
	err2 = errno;
	if (r1 == r2 && err1 == err2 && strcmp(buff1, buff2) == 0)
		printf("OK\n");
	else
	{
		printf("|%s| vs |%s|\n", buff1, buff2);
		printf("%-7d vs %7d\n", r1, r2);
		printf("errno %-7d vs %7d\n", err1, err2);
	}
}

void	strdup_test(const char *s)
{
	char *str1;
	char *str2;

	str1 = strdup(s);
	str2 = ft_strdup(s);
	if (str1 != str2 && ft_strcmp(str1, str2) == 0)
		printf("OK\n");
	else
		printf("str1:|%s|\n\tvs\nstr2:|%s|\n\n", str1, str2);
	free(str1);
	free(str2);
}

void strlen_test(char *str)
{
	int r1;
	int r2;

	r1 = ft_strlen(str);
	r2 = strlen(str);
	if (r1 == r2)
		printf("OK\n");
	else
		printf("%-10d vs %10d\n", r1, r2);
}

int		main(void)
{
	int fd1;
	int fd2;
	printf("\e[1;34m======= ft_strlen =======\e[0m\n");
	strlen_test("");
	strlen_test("\n");
	strlen_test("a");
	strlen_test("Hello");
	strlen_test("Hel\0lo");

	printf("\e[1;34m======= ft_strcpy =======\e[0m\n");
	strcy_test("hello moto");
	strcy_test("");
	strcy_test("aaaa\0aaaa");
	strcy_test("aaaaaaasdfa sdfasdfaksjdalkdbw,we mwne a mwngaa");

	printf("\e[1;34m======= ft_strcmp =======\e[0m\n");
	strcmp_test("", "");
	strcmp_test("asdklfjasdfj////asdf'''asdf3##\"", "asdklfjasdfj////asdf'''asdf3##\"");
	strcmp_test("a", "a");
	strcmp_test("a", "aa");
	strcmp_test("aaaaa", "");
	strcmp_test("", "aaaa");
	strcmp_test("asdasdas", "qfoprqqq");
	strcmp_test("a\n", "a\200");
	strcmp_test("a\n", "a\200");
	strcmp_test("a\xff", "a");
	

	printf("\e[1;34m======= ft_write =======\e[0m\n");
	write_test(1, "ft_write test plz\n", 18);
	write_test(1, "ft_write test plz\n", 0);
	write_test(1, "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.\n", 496);
	write_test(666, "ft_write test plz\n", 18);
	write_test(1, "", 0);
	write_test(1, 0, 0);
	write_test(666, "", 0);
	write_test(1, "ft_write test plz\n", -18);
	write_test(666, "ft_write test plz\n", -18);
	write_test(1, 0, 5);
	fd1 = open("/tmp/test_write_original", O_CREAT | O_TRUNC | O_RDWR);
	fd2 = open("/tmp/test_write_mine", O_CREAT | O_TRUNC | O_RDWR);
	write(fd1, "ft_write test plz\n", 5);
	ft_write(fd2, "ft_write test plz\n", 5);
	system("chmod 777 /tmp/test_write_original");
	system("chmod 777 /tmp/test_write_mine");
	system("cat /tmp/test_write_original; echo ''");
	system("cat /tmp/test_write_mine; echo ''");
	close(fd1);
	close(fd2);


	printf("\e[1;34m======= ft_read =======\e[0m\n");
	read_test(1, 1, 10, 0);
	read_test(666, 666, 10, 0);

	fd1 = open("/tmp/test_write_original", O_RDWR);
	fd2 = open("/tmp/test_write_mine", O_RDWR);
	read_test(fd1, fd2, 10, 0);
	close(fd1);
	close(fd2);
	fd1 = open("/tmp/test_write_original", O_RDWR);
	fd2 = open("/tmp/test_write_mine", O_RDWR);
	read_test(fd1, fd2, -10, 0);
	read_test(fd1, fd2, 10, 1);
	read_test(fd1, fd2, 0, 1);
	close(fd1);
	close(fd2);

	printf("\e[1;34m======= ft_strdup =======\e[0m\n");
	strdup_test("");
	strdup_test("assdasjdakjskjahsfkjhdf");
	strdup_test("assdasjda\0kjskjahsfkjhdf");
	return (0);
}


