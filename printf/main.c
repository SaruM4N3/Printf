/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:46:01 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/05 00:47:54 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("MONKEYS %cre in the %s;\n true: %d\n", 'a', "place", \
printf("MONKEYS %cre in the %s ;", 'a', "place"));
	ft_printf("MONKEYS %cre in the %s\n; false: %d\n", 'a', "place", \
ft_printf("MONKEYS %cre in the %s ;", 'a', "place"));
	return (0);
}
