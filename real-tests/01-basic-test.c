/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-basic-test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:43:31 by moe               #+#    #+#             */
/*   Updated: 2025/07/18 23:16:37 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"tests.h"

int basic_line_test(void) {
	int fd = open("testfiles/basic.txt", O_RDONLY);
	printf("%d\n",fd);
	if (fd < 0)
		return (-1);
	char *line = get_next_line(fd);
	if (strcmp(line, "Hello World\n") == 0)
		return 0;
	else
		return -1;
}

