/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:29 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/04 20:30:34 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_space_and_sign_increment(const char *str, size_t *i, int *sign)
{
	*i = 0;
	while (str[*i] && ((str[*i] == ' ') || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		sign;

	num = 0;
	ft_space_and_sign_increment(str, &i, &sign);
	while (str[i] && !(str[i] < 48 || str[i] > 57))
	{
		if (num == (num * 10 + (str[i] - 48)) / 10)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * sign);
}
/*
int	main(int ac, char **av)
{
	printf("%d\n", atoi(av[1]));
	printf("%d\n", ft_atoi(av[1]));
	return (1);
}
*/
