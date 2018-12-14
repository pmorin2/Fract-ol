/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:16:55 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/28 17:18:17 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **dst, const char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	return (dst);
}