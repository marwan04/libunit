/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:25:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 20:25:03 by moe              ###   ########.fr       */
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

	list = NULL;
	load_test(&list, "OK test", &ok_test);
	load_test(&list, "KO test", &ko_test);
	load_test(&list, "SEGV test", &segv_test);
	load_test(&list, "BUS test", &bus_test);
	cleanup_tests(list);
	return (launch_tests(&list));
}
