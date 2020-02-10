/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:23:30 by mclaudel          #+#    #+#             */
/*   Updated: 2020/02/10 13:59:58 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>

int main(void)
{
	printf("STARTING TESTS\n");
	
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("\n"));
	printf("%d\n", ft_strlen("a"));
	printf("%d\n", ft_strlen("Hello"));

	char src[10] = "HELLO MOTO";
	char dest[10];
	ft_strcpy(dest, src);
	printf("|%s|\n", src);
	printf("|%s|\n", dest);
	printf("END OF TESTS\n");
	return (0);
}
