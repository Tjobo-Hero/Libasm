/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 12:06:56 by tim           #+#    #+#                 */
/*   Updated: 2020/06/03 11:17:49 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		main(void)
{
	int		i;
	int		fd;
	char	dst[100];
	char	buffer[100];
	char	result[100];
	long	ret;

	i = 0;
	while (i < 100)
	{
		dst[i] = 0;
		buffer[i] = 0;
		result[i] = 0;
		i++;
	}

	/*                                TEST_STRLEN 						*/
	printf("------------------------->STRLEN<------------------------\n");
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "ASDF",
	(int)ft_strlen("ASDF"), (int)strlen("ASDF"));
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "LONG SENTENCE",
	(int)ft_strlen("LONG SENTENCE"), (int)strlen("LONG SENTENCE"));
	printf("STRING:'%s'\nOWN: [%d]\nREAL:[%d]\n", "O",
	(int)ft_strlen("O"), (int)strlen("O"));
	printf("------------>GOOD BEGINNING IS HALF THE WORK<------------\n\n");

	/*                                TEST_STRCMP						*/
	printf("------------------------>STRCMP<-------------------------\n");
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("Wester", "WAlter"),
	ft_strcmp("Wester", "Walter"));
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("OK", "XOXO"),
	ft_strcmp("OK", "XOXO"));
	printf("REAL:[%d] --- OWN:[%d]\n", strcmp("THE SAME", "THE SAME"),
	ft_strcmp("THE SAME", "THE SAME"));
	printf("---------------------->UNSTOPPABLE<----------------------\n\n");

	/*                                TEST_STRCPY						*/
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
	
	/*                                TEST_READ							*/
	printf("-------------------------->READ<-------------------------\n");
	errno = 0;
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("MY READ: %zd - %s\n", ret, strncpy(result, buffer, 10));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("REAL READ: %zd - %s\n", ret, strncpy(result, buffer, 10));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("MY READ: %zd - %s\n", ret, strncpy(result, buffer, 50));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("REAL READ: %zd - %s\n", ret, strncpy(result, buffer, 50));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("MY READ: %zd - %s\n", ret, strncpy(result, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("REAL READ:  %zd - %s\n", ret, strncpy(result, buffer, 10));
	close(fd);
	printf("\n");
	perror("ERRNO RESULT");
	printf("-------------------->GETTING TO THE END<-----------------\n\n");

	/*                                TEST_WRITE						*/
	printf("-------------------------->WRITE<-------------------------\n");
	errno = 0;
	ft_write(1, "TIM VAN CITTERS", 3);
	printf("\n");
	write(1, "TIM VAN CITTERS", 3);
	printf("\n");
	
	ft_write(1, "CHECK YOURSELF", 14);
	printf("\n");
	write(1, "CHECK YOURSELF", 14);
	printf("\n");
	
	ft_write(1, "PLEASE TEST ME", 14);
	printf("\n");
	write(1, "PLEASE TEST ME", 14);
	printf("\n");

	ft_write(0, "TEST", 4);
	printf("\n");
	write(0, "TEST", 4);
	printf("\n");

	ft_write(1, NULL, 5);
	printf("\n");
	write(1, NULL, 5);
	printf("\n");
	
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	fd = open("test_write", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	write(fd, "REAL TOTO", 9);
	ft_write(fd, "MY TOTO", 9);
	close(fd);
	fd = open("test_write", O_RDONLY);
	read(fd, buffer, 9);
	printf("REAL WRITE: [%s]\n", buffer);
	read(fd, buffer, 9);
	printf("MY WRITE: [%s]\n", buffer);
	close(fd);
	remove("test_write");

	printf("\n");
	perror("ERRNO RESULT");
	printf("-------------------->ONE MORE TO GO!<-----------------\n\n");
	/*                                TEST_STRDUP						*/
	printf("-------------------------->STRDUP<-------------------------\n");
	printf("REAL:[%s]\n", strdup("TEST"));
	printf("MY:  [%s]\n", ft_strdup("TEST"));
	printf("\n");
	printf("REAL:[%s]\n", strdup("YOU LIKE"));
	printf("MY:  [%s]\n", ft_strdup("YOU LIKE"));
	printf("\n");
	printf("REAL:[%s]\n", strdup("I LIKE TO COUNT 1234567"));
	printf("MY:  [%s]\n", ft_strdup("I LIKE TO COUNT 1234567"));
	printf("\n");
	// printf("REAL:[%s]\n", strdup(NULL));
	// printf("MY: [%s]\n", ft_strdup(NULL));
	printf("-------------------->!!!FINISH!!!<-----------------\n\n");
	return (0);
}
