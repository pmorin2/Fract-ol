/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:18:32 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/08 14:08:03 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i] && haystack[i] != needle[0] && i < len)
			i++;
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j] && (i + j) < len)
			j++;
		if (!(needle[j]))
			return (&((char*)haystack)[i]);
		if (haystack[i])
			i++;
	}
	return (NULL);
}
