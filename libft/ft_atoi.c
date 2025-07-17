/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:48:07 by msalim            #+#    #+#             */
/*   Updated: 2024/09/03 18:37:09 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
/*int main(void)
{
   printf("%d\n", ft_atoi("123"));           // Expected: 123
	printf("%d\n", ft_atoi("--123"));          // Expected: 0
	printf("%d\n", ft_atoi("   +42"));        // Expected: 42
	printf("%d\n", ft_atoi("42 is the answer")); // Expected: 42
	printf("%d\n", ft_atoi("0000123"));       // Expected: 123
	printf("%d\n", ft_atoi("123abc"));        // Expected: 123
	printf("%d\n", ft_atoi("abc123"));        // Expected: 0 (non-numeric start)

	return (0);
}*/
