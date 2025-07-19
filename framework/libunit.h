/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:40 by alrfa3i           #+#    #+#             */
/*   Updated: 2025/07/19 20:33:51 by alrfa3i          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_unit_test
{
	char				*name;
	int					(*test_func)(void);
	struct s_unit_test	*next;
}						t_unit_test;

typedef struct s_data
{
	t_unit_test	*cur;
	int			total;
	int			success;
	pid_t		pid;
	int			status;
	int			result;
}						t_data;

void					load_test(t_unit_test **list, char *name,
							int (*test_func)(void));
int						launch_tests(t_unit_test **list);
void					cleanup_tests(t_unit_test *list);

#endif
