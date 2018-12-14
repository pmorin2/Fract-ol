/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:05:30 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/09 13:14:57 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
			i++;
		if (i == n && i > 0 && s1[i - 1] == s2[i - 1])
			return (1);
		if (n == 0)
			return (1);
		if (s1[i] == s2[i])
			return (1);
		return (0);
	}
	return (0);
}
