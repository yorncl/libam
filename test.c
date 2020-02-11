/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:23:30 by mclaudel          #+#    #+#             */
/*   Updated: 2020/02/11 16:07:23 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void	strcmp_test(char *s1, char *s2)
{
	printf("%d\t %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	printf("%d\t %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}

int main(void)
{
	// printf("%d\n", ft_strlen(""));
	// printf("%d\n", ft_strlen("\n"));
	// printf("%d\n", ft_strlen("a"));
	// printf("%d\n\n", ft_strlen("Hello"));

	// char src [11] = "HELLO MOTO";
	// char dest [11];
	// ft_strcpy(dest, src);
	// printf("|%p|\n", src);
	// printf("|%s|\n", src);
	// printf("|%p|\n", dest);
	// printf("|%s|\n\n", dest);

	// strcmp_test("", "");
	// strcmp_test("a", "a");
	// strcmp_test("a", "aa");
	// strcmp_test("aaaaa", "");
	// strcmp_test("", "aaaa");
	// strcmp_test("asdasdas", "qfoprqqq");
	// strcmp_test("a", "a\200");
	
	int r = ft_write(1, "ft_write test plz\n", 18);
	printf("%d\n", r);
	r = ft_write(1, "ft_write test plz\n", 18);
	printf("%d\n", r);

	printf("\n\n\n\n\n");
	
	char buff[10];
	while (ft_read(open("libasm.h", O_RDONLY), buff, 10))
		printf("r: %s\n", buff);

	// printf("END OF TESTS\n");
	return (0);
}
