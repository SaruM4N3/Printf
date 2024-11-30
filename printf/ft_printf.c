/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:30:24 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/30 07:11:54 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list ptr;

	va_start(ptr,str);
	while (*str)
	{
		ft_printf_parse();
	}
	va_end(ptr);

	return (0);
}
