/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:54:44 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/20 17:23:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	new;

	if (n < 0)
		ft_putchar('-');
	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar(new + 48);
	else
	{
		ft_putnbr(new / 10);
		ft_putchar(new % 10 + 48);
	}
}
