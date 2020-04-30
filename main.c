/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 12:06:56 by tim           #+#    #+#                 */
/*   Updated: 2020/04/30 13:44:43 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t  ft_strlen(const char *str);

int		main(void)
{
	int test_strlen;

	test_strlen = ft_strlen("TEST");
	printf("STRLEN: [%i]\n", test_strlen);
}
