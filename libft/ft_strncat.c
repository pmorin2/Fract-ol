/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:47:46 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/07 21:20:01 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	cpy = (char*)s2;
	while (*s1)
	{
		s1++;
		i++;
	}
	j = 0;
	while (*cpy && j < n)
	{
		*s1 = *cpy;
		cpy++;
		s1++;
		j++;
	}
	*s1 = 0;
	return (s1 - i - j);
}
