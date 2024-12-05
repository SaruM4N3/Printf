/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 03:09:45 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/05 04:19:47 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

void	ft_putnbr_base(unsigned long nbr, char *base, int fd, size_t *fsize)
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
		ft_putnbr_base(unbr / ft_strlen(base), base, fd, fsize);
		ft_putnbr_base(unbr % ft_strlen(base), base, fd, fsize);
	}
}
