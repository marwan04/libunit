/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_ft_bzero_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:38:52 by moe               #+#    #+#             */
/*   Updated: 2025/07/19 18:39:12 by moe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int test_bzero_basic(void) {
  char buffer[10] = "Hello";
  ft_bzero(buffer, 3);

  // Check that first 3 bytes are zero
  if (buffer[0] == '\0' && buffer[1] == '\0' && buffer[2] == '\0' &&
      buffer[3] == 'l')
    return (0);
  return (-1);
}
