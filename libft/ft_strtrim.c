/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:38:21 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/09 14:50:40 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	*count_blank(const char *s)
{
	size_t	*blank;
	size_t	i;
	size_t	len;

	i = 0;
	if (!(blank = (size_t*)ft_memalloc(2)))
		return (NULL);
	len = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	blank[0] = i;
	i = len;
	while (i != blank[0] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
				|| s[i] == 0))
		i--;
	blank[1] = i;
	return (blank);
}

char			*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	*blank;
	char	*trim;

	if (s)
	{
		if (!(blank = count_blank(s)))
			return (NULL);
		if (!(trim = ft_strnew(blank[1] - blank[0] + 1)))
			return (NULL);
		i = blank[0];
		while (i <= blank[1])
		{
			trim[i - blank[0]] = s[i];
			i++;
		}
		return (trim);
	}
	return (NULL);
}
