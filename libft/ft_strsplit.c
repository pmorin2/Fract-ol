/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:20:40 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/12 11:37:46 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static size_t	len_k_word(const char *s, char c, size_t k)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		count++;
		if (count == k)
			break ;
		while (s[i] && s[i] != c)
			i++;
	}
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char		**split(char **tab, size_t k[2], const char *s, char c)
{
	size_t	i;
	size_t	words;

	words = count_words(s, c);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (len_k_word(s, c, k[0] + 1) == 0)
			break ;
		if (!(tab[k[0]] = ft_strnew(len_k_word(s, c, k[0] + 1))))
			return (NULL);
		k[1] = 0;
		while (s[i] && s[i] != c)
		{
			tab[k[0]][k[1]] = s[i];
			i++;
			k[1]++;
		}
		k[0]++;
	}
	tab[k[0]] = 0;
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	k[2];
	size_t	words;

	if (s)
	{
		k[0] = 0;
		k[1] = 0;
		words = count_words(s, c);
		if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
			return (NULL);
		if (!(tab = split(tab, k, s, c)))
		{
			while (k[0]--)
				free(tab[k[0]]);
			return (NULL);
		}
		return (tab);
	}
	return (NULL);
}
