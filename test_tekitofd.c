/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tekitofd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:42:12 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/19 17:40:23 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		fd;
	int		res;

	fd = 42;
	printf("fd = %d\n", fd);
	line = NULL;
	res = get_next_line(fd, &line);
	printf("res = %d, line = \"%s\"\n", res, line);

	fd = -42;
	printf("fd = %d\n", fd);
	line = NULL;
	res = get_next_line(fd, &line);
	printf("res = %d, line = \"%s\"\n", res, line);

	fd = 1;
	printf("fd = %d\n", fd);
	line = NULL;
	res = get_next_line(fd, &line);
	printf("res = %d, line = \"%s\"\n", res, line);

	fd = 2;
	printf("fd = %d\n", fd);
	line = NULL;
	res = get_next_line(fd, &line);
	printf("res = %d, line = \"%s\"\n", res, line);

	return (0);
}
