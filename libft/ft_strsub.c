/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:16:44 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/09 13:22:14 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*trunc;

	if (s)
	{
		i = 0;
		if (!(trunc = ft_strnew(len)))
			return (NULL);
		while (i < len)
		{
			trunc[i] = s[start + i];
			i++;
		}
		return (trunc);
	}
	return (NULL);
}
