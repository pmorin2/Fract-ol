/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:37:20 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/08 14:05:25 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] && haystack[i] != needle[0])
			i++;
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (needle[j] == 0)
			return (&((char*)haystack)[i]);
		if (haystack[i])
			i++;
	}
	return (NULL);
}
