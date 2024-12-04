/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:31:36 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/04 04:21:37 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_action(char current, va_list args)
{
	if (current == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (current == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (current == 'p')
		return ('p');
	else if (current == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (current == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (current == 'u')
		return ('u');
	else if (current == 'x')
		return ('x');
	else if (current == 'X')
		return ('X');
	else if (current == '%')
		ft_putchar_fd('%', 1);
	return (-1);
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