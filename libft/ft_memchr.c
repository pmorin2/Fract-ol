/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:28:20 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/14 13:42:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *byte;

	byte = (unsigned char*)s;
	while (n > 0)
	{
		if (*byte == (unsigned char)c)
			return (byte);
		n--;
		byte++;
	}
	return (NULL);
}
