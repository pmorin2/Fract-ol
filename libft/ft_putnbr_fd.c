/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:54:44 by msiesse           #+#    #+#             */
/*   Updated: 2018/11/20 17:23:45 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new;

	if (fd > 0)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		new = (n > 0) ? n : -n;
		if (new < 10)
			ft_putchar_fd(new + 48, fd);
		else
		{
			ft_putnbr_fd(new / 10, fd);
			ft_putchar_fd(new % 10 + 48, fd);
		}
	}
}
