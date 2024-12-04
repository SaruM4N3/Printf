/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:57:39 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/24 17:47:03 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

// #include <stdlib.h>
// int	main(void)
// {
// 	char	str[] = "skjdskfbacjdsjfbaci";
// 	char	to_find[8] = "baci";
// 	size_t	l = 50;
// 	__builtin_printf("The str is : %s\n", str);
// 	__builtin_printf("The word to copy is : %s\n", to_find);
// 	__builtin_printf("The result is : %s", ft_strnstr(str, to_find, l));
// }
