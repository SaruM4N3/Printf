/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:28:11 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/24 14:03:09 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);	
	while (s[i] && s[i] != (char ) c)
	{
		i++;
	}
	if (s[i] == (char ) c)
		return (&((char *)s)[i]);
	return (0);
}
