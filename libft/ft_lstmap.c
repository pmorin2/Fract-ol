/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:09:37 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/13 12:16:46 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*head;

	if (alst && new)
	{
		head = *alst;
		if (*alst == NULL)
		{
			*alst = new;
			return (1);
		}
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
		*alst = head;
		return (1);
	}
	return (0);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new = f(new);
		if (!(ft_lstpush(&head, new)))
		{
			free(new);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
