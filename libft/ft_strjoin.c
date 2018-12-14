/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:25:53 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/09 13:37:09 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*conc;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(conc = ft_strnew(len1 + len2)))
			return (NULL);
		i = 0;
		while (i < len2 + len1)
		{
			if (i < len1)
				conc[i] = s1[i];
			else
				conc[i] = s2[i - len1];
			i++;
		}
		return (conc);
	}
	return (NULL);
}
