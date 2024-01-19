/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:59:59 by abolea            #+#    #+#             */
/*   Updated: 2023/11/28 10:37:36 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int *i)
{
	if (n != -2147483648)
	{
		if (n < 0)
		{
			if (ft_putchar_fd('-', fd) < 0)
				return (-1);
			n = -n;
			(*i)++;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd, i);
		if (ft_putchar_fd((n % 10) + '0', fd) < 0)
			return (-1);
		(*i)++;
	}
	else
	{
		if (ft_putstr_fd("-2147483648", fd) < 0)
			return (-1);
		*i = 11;
	}
	return (*i);
}
