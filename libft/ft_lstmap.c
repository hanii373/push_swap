/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:41:46 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/10 16:59:38 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lst1;

	lst1 = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		tmp = ft_lstnew(f(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&lst1, del);
			return (0);
		}
		ft_lstadd_back(&lst1, tmp);
		lst = lst -> next;
	}
	return (lst1);
}
