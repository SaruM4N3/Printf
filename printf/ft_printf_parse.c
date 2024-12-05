/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:31:36 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/05 02:56:58 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putchar_iter(char c, int fd, size_t *fsize)
{
	if (fd < 0)
		return ;
	(*fsize)++;
	write(fd, &c, 1);
}

static void	ft_putstr_iter(char *s, int fd, size_t *fsize)
{
	int	i;

	i = 0;
	if (!s)
	{
		(*fsize) += 6;
		write(fd, "(null)", 6);
		return ;
	}
	(*fsize) += ft_strlen(s);
	if (write(fd, s, ft_strlen(s)) < 0)
		return ;
}

static void	ft_putnbr_iter(int n, int fd, size_t *fsize)
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
		ft_putnbr_iter(un / 10, fd, fsize);
		ft_putnbr_iter(un % 10, fd, fsize);
	}
}

int	ft_printf_action(char current, va_list args, size_t *fsize)
{
	if (current == 'c')
		ft_putchar_iter(va_arg(args, int), 1, fsize);
	else if (current == 's')
		ft_putstr_iter(va_arg(args, char *), 1, fsize);
	else if (current == 'p')
		return ('p');
	else if (current == 'd')
		ft_putnbr_iter(va_arg(args, int), 1, fsize);
	else if (current == 'i')
		ft_putnbr_iter(va_arg(args, int), 1, fsize);
	else if (current == 'u')
		return ('u');
	else if (current == 'x')
		return ('x');
	else if (current == 'X')
		return ('X');
	else if (current == '%')
	{
		ft_putchar_fd('%', 1);
		(*fsize)++;
	}
	return (0);
}

/*
TODO:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/