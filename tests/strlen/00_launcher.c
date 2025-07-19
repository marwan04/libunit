/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:25:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 20:36:24 by alrfa3i          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"

int	ok_test(void);
int	ko_test(void);
int	segv_test(void);
int	bus_test(void);

int	strlen_launcher(void)
{
	t_unit_test	*list;
	int			result;

	list = NULL;
	load_test(&list, "OK test", &ok_test);
	load_test(&list, "KO test", &ko_test);
	load_test(&list, "SEGV test", &segv_test);
	load_test(&list, "BUS test", &bus_test);
	result = launch_tests(&list);
	if (list)
		cleanup_tests(list);
	return (result);
}
