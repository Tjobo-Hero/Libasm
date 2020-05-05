/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 12:06:56 by tim           #+#    #+#                 */
/*   Updated: 2020/05/05 19:00:21 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "libasm.h"

void	test_strlen_and_strcmp(void)
{
	printf("------------------------->STRLEN<------------------------\n");
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "ASDF",
	(int)ft_strlen("ASDF"), (int)strlen("ASDF"));
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "LONG SENTENCE",
	(int)ft_strlen("LONG SENTENCE"), (int)strlen("LONG SENTENCE"));
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "O",
	(int)ft_strlen("O"), (int)strlen("O"));
	printf("------------>GOOD BEGINNING IS HALF THE WORK<------------\n\n");
	printf("------------------------>STRCMP<-------------------------\n");
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("Wester", "WAlter"),
	ft_strcmp("Wester", "Walter"));
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("OK", "XOXO"),
	ft_strcmp("OK", "XOXO"));
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("THE SAME", "THE SAME"),
	ft_strcmp("THE SAME", "THE SAME"));
	printf("---------------------->UNSTOPPABLE<----------------------\n\n");
}

void	test_strcpy(void)
{
	int		i;
	char	dst[100];

	i = 0;
	while (i < 100)
	{
		dst[i] = 0;
		i++;
	}
	printf("------------------------>STRCPY<-------------------------\n");
	printf("MY STRCPY:   [%s]| -- ", ft_strcpy(dst, "TEST"));
	printf("REAL STRCPY: [%s]|\n\n", strcpy(dst, "TEST"));
	printf("MY STRCPY:   [%s]| -- ", ft_strcpy(dst, ""));
	printf("REAL STRCPY: [%s]|\n\n", strcpy(dst, ""));
	printf("MY STRCPY:   [%s]| -- ", ft_strcpy(dst, "PLEASE MAKE SOMETHING"));
	printf("REAL STRCPY: [%s]|\n\n", strcpy(dst, "PLEASE MAKE SOMETHING"));
	// printf("MY STRCPY:   [%s] NULL STRING NOT MODIFIED | -- ", ft_strcpy(dst, NULL));
	// printf("REAL STRCPY: [%s]|\n", strcpy(dst, "SEGMENTATIONFAULT"));
	printf("---------------------->GREAT SUCCES<---------------------\n\n");
}

void	test_read_and_write(void)
{
	char	real_buffer[1000];
	char	real_print[1000];
	ssize_t	ret;

	ret = read(STDIN_FILENO, real_buffer, 15);
	real_buffer[ret] = 0;
	printf("-------------------------->READ<-------------------------\n");
	printf("READ:\n%s\nRET:[%zd]\n", strncpy(real_print, real_buffer, 15), ret);
	printf("-------------------->GETTING TO THE END<-----------------\n\n");
}

int		main(void)
{
	test_strcpy();
	test_strlen_and_strcmp();
	test_read_and_write();
	return (0);
}
