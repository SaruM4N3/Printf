/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:10:02 by zsonie            #+#    #+#             */
/*   Updated: 2024/11/24 06:39:48 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	**last;
	void	*f_res;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	last = &newlst;
	while (lst)
	{
		f_res = f(lst->content);
		*last = ft_lstnew(f_res);
		if (!*last || !f_res)
		{
			del(f_res);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		last = &((*last)->next);
		lst = lst->next;
	}
	return (newlst);
}
