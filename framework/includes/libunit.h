/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:40 by alrfa3i           #+#    #+#             */
/*   Updated: 2025/07/17 17:50:48 by alrfa3i          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

typedef struct s_unit_test
{
	char *name;
	int (*test_func)(void);
	struct s_unit_test *next;
}	t_unit_test;

void	init_test(t_unit_test **list, char *name, int (*test_func)(void));
int		launch_tests(t_unit_test **list);
void	cleanup_tests(t_unit_test *list);

#endif
