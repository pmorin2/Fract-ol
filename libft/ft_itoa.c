/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:07:06 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/20 17:22:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while ((n = n / 10) != 0)
		size++;
	return (size);
}

static int	ft_pow(int n, int power)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i++ < power)
		result *= n;
	return (result);
}

char		*ft_itoa(int n)
{
	char			*nbr;
	size_t			i;
	size_t			len;
	unsigned int	un;

	i = 0;
	len = get_size(n);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	if (n < 0 && ++i)
		nbr[0] = '-';
	un = (n > 0) ? n : -n;
	while (i < len)
	{
		nbr[i] = un / ft_pow(10, len - i - 1) + 48;
		un %= ft_pow(10, len - i - 1);
		i++;
	}
	return (nbr);
}
