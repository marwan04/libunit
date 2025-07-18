/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:35:40 by moe               #+#    #+#             */
/*   Updated: 2025/07/18 23:24:51 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../framework/libunit.h"
#include	"tests.h"

int	launcher(void)
{
	t_unit_test	*tests = NULL;

	load_test(&tests,"basic text", &basic_line_test);
	return (launch_tests(&tests));
}
