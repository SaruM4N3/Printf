/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:45:40 by zsonie            #+#    #+#             */
/*   Updated: 2024/12/04 01:51:48 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h" 

int	main()
{
	// __builtin_printf("monkeys %cre %d in the %s;\n printfresult: %i\n", 'a', 10,"place",\
// __builtin_printf("monkeys %cre %d in the %s;\n", 'a', 10,"place"));
// 
	// ft_printf("monkeys %cre %d in the %s;\n printfresult: %i\n", 'a', 10,"place",\
	//  ft_printf("monkeys %cre %d in the %s;\n", 'a', 10,"place"));
	//  
	ft_printf("FALSE: monkeys %cre %s %d; %i\n", 'a', "bsfjhdbfjusehbfds", 481516 , 2342);	 
	__builtin_printf("\nTRUE: monkeys %cre ;\n", 'a');	 
	}
