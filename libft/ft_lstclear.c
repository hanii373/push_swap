/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:23:57 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/10 16:32:05 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (!del || !lst)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr -> next;
		del(curr -> content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
