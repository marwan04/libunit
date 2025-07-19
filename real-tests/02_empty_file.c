/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-empty-file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:44:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/18 23:49:48 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

int	empty_file_test(void)
{
	int		fd;
	char	*line;

	fd = open("real-tests/testfiles/02-empty-file.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	close(fd);
	if (line == NULL)
		return (0);
	free(line);
	return (-1);
}
