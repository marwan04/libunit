/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:35:40 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:22:41 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "tests.h"

int launcher(void) {
  t_unit_test *tests = NULL;

  load_test(&tests, "basic text", &basic_line_test);
  load_test(&tests, "empty file test", &empty_file_test);
  load_test(&tests, "ft_strcpy basic_test", &test_strcpy_basic);
  load_test(&tests, "ft_strcpy empty_test", &test_strcpy_empty);
  load_test(&tests, "ft_strncmp_equal_test", &test_strncmp_equal);
  load_test(&tests, "ft_strncmp_different_test", &test_strncmp_different);
  load_test(&tests, "ft_atoi_basic_test", &test_atoi_basic);
  load_test(&tests, "ft_atoi_negative_test", &test_atoi_negative);
  return (launch_tests(&tests));
}
