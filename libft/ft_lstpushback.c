/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:09:37 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/14 13:40:44 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushback(t_list **alst, t_list *new)
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
