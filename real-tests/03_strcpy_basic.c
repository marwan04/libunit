/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strcpy_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:49:43 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:57:04 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_strcpy_basic(void)
{
	char	dest[20];

	ft_strcpy(dest, "Hello");
	if (ft_strcmp(dest, "Hello") == 0)
		return (0);
	return (-1);
}
