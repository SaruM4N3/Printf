/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:07:29 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/24 17:03:39 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		un = (unsigned int) -n;
		write (fd, "-", 1);
	}
	else
		un = n;
	if (un <= 9)
	{
		c = un + 48;
		write (fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
}
