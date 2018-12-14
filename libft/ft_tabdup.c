/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:13:29 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/28 17:16:48 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src)
{
	char	**dup;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (!(dup = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = ft_strdup(src[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
