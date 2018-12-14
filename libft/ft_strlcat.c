/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:21:07 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/11 13:29:08 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;
	char	*cpy;

	length = ft_strlen(src);
	cpy = (char*)src;
	i = 0;
	while (*dst)
	{
		dst++;
		if (i < size)
			length++;
		i++;
	}
	while (++i < size && *cpy)
	{
		*dst = *cpy;
		dst++;
		cpy++;
	}
	*dst = 0;
	return (length);
}
