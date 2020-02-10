/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:23:30 by mclaudel          #+#    #+#             */
/*   Updated: 2020/02/10 13:12:11 by mclaudel         ###   ########.fr       */
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

	printf("END OF TESTS\n");
	return (0);
}