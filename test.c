/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:42:12 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/20 11:10:28 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd[N_FDMAX];
	int		flag_notfinished;
	char	*line;
	int		res;
	int		flag_stdin;

	if (argc == 1)
	{
		fd[0] = 0;
		argc = 2;
		flag_stdin = 1;
	}
	else
	{
		i = 0;
		while (i < argc - 1)
		{
			fd[i] = open(argv[i + 1], O_RDONLY);
			i++;
		}
	}
	flag_notfinished = 1;
	i = 0;
	while (flag_notfinished)
	{
		flag_notfinished = 0;
		printf("GNL: %d\n", i);
		j = 0;
		while (j < argc - 1)
		{
			if (fd[j] != -2)
			{
				res = get_next_line(fd[j], &line);
				printf("fd-%03d: res = %2d", fd[j], res);
				if (res == -1)
				{
					printf(", ERROR!!\n");
					fd[j] = -2;
				}
				else
				{
					flag_notfinished += res;
					printf(", line = \"%s\"\n", line);
					free(line);
					if (res == 0)
					{
						if (fd[j] > 2)
							close(fd[j]);
						fd[j] = -2;
					}
				}
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("finished\n");
	#ifdef LEAKCHECK
	while(1);
	#endif
}
