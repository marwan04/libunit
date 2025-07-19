/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:56:02 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:19:19 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "../libft/libft.h"
int basic_line_test(void);
int empty_file_test(void);
int long_line_test(void);
int test_strcpy_basic(void);
int test_strcpy_empty(void);
int test_strncmp_different(void);
int test_strncmp_equal(void);
int test_atoi_basic(void);
int test_atoi_invalid(void);
int test_atoi_negative(void);
int launcher(void);
#endif
