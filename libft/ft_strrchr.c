/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:26:19 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/08 09:35:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		last;

	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (int)i;
		i++;
	}
	if (s[i] == (char)c)
		return (&((char*)s)[i]);
	if (last != -1)
		return (&((char*)s)[last]);
	return (NULL);
}
