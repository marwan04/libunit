/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strcpy_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:06:11 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 19:00:40 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_strcpy_empty(void)
{
	char	dest[10];

	ft_strcpy(dest, "test");
	ft_strcpy(dest, "");
	if (dest[0] == '\0')
		return (0);
	return (-1);
}
