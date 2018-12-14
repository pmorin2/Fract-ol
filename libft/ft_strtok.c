/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:50:54 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/13 14:17:18 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *sep)
{
	static char	*save;
	size_t		i;

	if (str == NULL && save != NULL)
		str = save;
	if (str)
	{
		i = ft_strcspn(str, sep);
		str += i;
		save = str + ft_strspn(str, sep);
		if (!*save)
			save = NULL;
		*str = 0;
		return (str - i);
	}
	return (NULL);
}
