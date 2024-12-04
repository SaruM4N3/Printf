/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:06:53 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/24 23:45:19 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	if (!s || fd <= 0)
		return ;
	i = 0;
	while (s[i])
	{
		if (write (fd, &s[i], 1) < 0)
			return ;
		i++;
	}
	write (fd, "\n", 1);
}

// int main(void)
// {
// 	ft_putendl_fd("asjgdjdshbgfdsjjfbxcjhbviks", 0);
// }