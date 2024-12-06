/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:06:56 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/06 05:26:17 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_is_valid(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	i = 0;
	j = 1;
	if (!base || len <= 1)
		return (1);
	while (base[i] && i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j] && (base[i] != base[j]))
			j++;
		if (base[i] == base[j])
			return (1);
		i++;
		j = i + 1;
	}
	return (0);
}

void	ft_putnbr_int(int n, int fd, size_t *fsize)
{
	unsigned int	un;
	char			c;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		un = (unsigned int)-n;
		(*fsize)++;
		write(fd, "-", 1);
	}
	else
		un = n;
	if (un <= 9)
	{
		(*fsize)++;
		c = un + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_int(un / 10, fd, fsize);
		ft_putnbr_int(un % 10, fd, fsize);
	}
}

void	ft_putnbr_base_ul(unsigned long nbr, char *base, int fd, size_t *fsize)
{
	unsigned long	unbr;

	if (ft_base_is_valid(base))
		return ;
	unbr = nbr;
	if (unbr < (unsigned long)ft_strlen(base))
	{
		(*fsize)++;
		ft_putchar_fd(base[unbr], fd);
	}
	else
	{
		ft_putnbr_base_ul(unbr / ft_strlen(base), base, fd, fsize);
		ft_putnbr_base_ul(unbr % ft_strlen(base), base, fd, fsize);
	}
}
